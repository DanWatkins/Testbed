#include "RenderThread.h"
#include "OpenGLQuickItem.h"

RenderThread::RenderThread(const QSize &size) :
	mSurface(nullptr),
	mContext(nullptr),
	mRenderFbo(nullptr),
	mDisplayFbo(nullptr),
	mLogoRenderer(nullptr),
	mSize(size)
{
	OpenGLQuickItem::enqueue(this);
}


void RenderThread::ready()
{
	mSurface = new QOffscreenSurface();
	mSurface->setFormat(mContext->format());
	mSurface->create();
}


void RenderThread::createContext(QOpenGLContext *sharedContext)
{
	mContext = new QOpenGLContext();
	mContext->setFormat(sharedContext->format());
	mContext->setShareContext(sharedContext);
	mContext->create();
	mContext->moveToThread(this);
}


void RenderThread::renderNext()
{
	mContext->makeCurrent(mSurface);

	if (!mRenderFbo)
	{
		// Initialize the buffers and renderer
		QOpenGLFramebufferObjectFormat format;
		format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
		mRenderFbo = new QOpenGLFramebufferObject(mSize, format);
		mDisplayFbo = new QOpenGLFramebufferObject(mSize, format);
		mLogoRenderer = new LogoRenderer();
		mLogoRenderer->initialize();
	}

	mRenderFbo->bind();
	glViewport(0, 0, mSize.width(), mSize.height());

	mLogoRenderer->render();

	// We need to flush the contents to the FBO before posting
	// the texture to the other thread, otherwise, we might
	// get unexpected results.
	glFlush();

	mRenderFbo->bindDefault();
	qSwap(mRenderFbo, mDisplayFbo);

	emit textureReady(mDisplayFbo->texture(), mSize);
}

void RenderThread::shutDown()
{
	qDebug() << "Shutting Down";

	mContext->makeCurrent(mSurface);
	delete mRenderFbo;
	delete mDisplayFbo;
	delete mLogoRenderer;
	mContext->doneCurrent();
	delete mContext;

	// schedule this to be deleted only after we're done cleaning up
	mSurface->deleteLater();

	// Stop event processing, move the thread to GUI and make sure it is deleted.
	exit();
	moveToThread(QGuiApplication::instance()->thread());
}

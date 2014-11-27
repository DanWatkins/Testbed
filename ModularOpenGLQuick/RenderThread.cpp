/*
 * Created by Dan Watkins on 2014.11.26
 * Content derived from the "Scene Graph - Rendering FBOs in a thread" example
 */

#include "RenderThread.h"
#include <QGuiApplication>

OpenGLQuickItem::RenderThread::RenderThread(const QSize &size) :
	mSurface(nullptr),
	mContext(nullptr),
	mFboRender(nullptr),
	mFboDisplay(nullptr),
	mSize(size)
{
	OpenGLQuickItem::mRenderThreads << this;
}


void OpenGLQuickItem::RenderThread::renderNext()
{
	mContext->makeCurrent(mSurface);

	if (!mFboRender)
	{
		QOpenGLFramebufferObjectFormat format;
		format.setAttachment(QOpenGLFramebufferObject::CombinedDepthStencil);
		mFboRender = new QOpenGLFramebufferObject(mSize, format);
		mFboDisplay = new QOpenGLFramebufferObject(mSize, format);

		//TODO call initialize on the delegate
	}

	mFboRender->bind();
	{
		glViewport(0, 0, mSize.width(), mSize.height());
		//TODO call render to the delegate
		glFlush();
	}
	mFboRender->bindDefault();

	qSwap(mFboRender, mFboDisplay);
	emit textureReady(mFboDisplay->texture(), mSize);
}

void OpenGLQuickItem::RenderThread::shutdown()
{
	mContext->makeCurrent(mSurface);
	{
		delete mFboRender;
		delete mFboDisplay;
	}
	mContext->doneCurrent();
	delete mContext;

	mSurface->deleteLater();
	exit();
	moveToThread(QGuiApplication::instance()->thread());
}

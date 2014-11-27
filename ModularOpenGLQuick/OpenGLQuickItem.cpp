/*
 * Created by Dan Watkins on 2014.11.26
 * Content derived from the "Scene Graph - Rendering FBOs in a thread" example
 */

#include "RenderThread.h"
#include "TextureNode.h"
#include "OpenGLQuickItem.h"

QList<OpenGLQuickItem::RenderThread*> OpenGLQuickItem::mRenderThreads;

OpenGLQuickItem::OpenGLQuickItem() :
	mRenderThread(nullptr)
{
	setFlag(ItemHasContents, true);
	mRenderThread = new RenderThread(QSize(512,512));
}


void OpenGLQuickItem::cleanupRenderThreads()
{
	foreach (RenderThread *rt, mRenderThreads)
	{
		rt->wait();
		delete rt;
	}
}


void OpenGLQuickItem::ready()
{
	mRenderThread->mSurface = new QOffscreenSurface();
	mRenderThread->mSurface->setFormat(mRenderThread->mContext->format());
	mRenderThread->mSurface->create();
	mRenderThread->moveToThread(mRenderThread);

	connect(window(), SIGNAL(sceneGraphInvalidated()), mRenderThread, SLOT(shutDown()), Qt::QueuedConnection);
	mRenderThread->start();
	update();
}


QSGNode* OpenGLQuickItem::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData*)
{
	TextureNode *node = static_cast<TextureNode*>(oldNode);

	if (!mRenderThread->mContext)
	{
		QOpenGLContext *current = window()->openglContext();
		current->doneCurrent(); //required for some OpenGL implementations

		mRenderThread->mContext = new QOpenGLContext();
		mRenderThread->mContext->setFormat(current->format());
		mRenderThread->mContext->setShareContext(current);
		mRenderThread->mContext->create();
		mRenderThread->mContext->moveToThread(mRenderThread);

		current->makeCurrent(window());
		QMetaObject::invokeMethod(this, "ready");

		return nullptr;
	}

	if (!node)
	{
		node = new TextureNode(window());

		connect(mRenderThread, SIGNAL(textureReady(int,QSize)), node, SLOT(newTexture(int,QSize)), Qt::DirectConnection);
		connect(node, SIGNAL(pendingNewTexture()), window(), SLOT(update()), Qt::QueuedConnection);
		connect(window(), SIGNAL(beforeRendering()), node, SLOT(prepareNode()), Qt::DirectConnection);
		connect(node, SIGNAL(textureInUse()), mRenderThread, SLOT(renderNext()), Qt::QueuedConnection);

		QMetaObject::invokeMethod(mRenderThread, "renderNext", Qt::QueuedConnection);
	}

	node->setRect(boundingRect());

	return node;
}

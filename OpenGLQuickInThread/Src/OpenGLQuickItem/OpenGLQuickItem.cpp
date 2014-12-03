#include "../OpenGLQuickItem.h"
#include "RenderThread.h"
#include "TextureNode.h"

QList<OpenGLQuickItem::RenderThread *> OpenGLQuickItem::mThreads;

OpenGLQuickItem::OpenGLQuickItem(IOpenGLRenderable *renderable) :
	mRenderThread(0)
{
    setFlag(ItemHasContents, true);
	mRenderThread = new RenderThread(QSize(512, 512), renderable);
}


void OpenGLQuickItem::endAllRenderThreads()
{
	foreach (RenderThread *t, OpenGLQuickItem::mThreads)
	{
		t->wait();
		delete t;
	}
}


void OpenGLQuickItem::enqueue(RenderThread *thread)
{
	mThreads << thread;
}


void OpenGLQuickItem::ready()
{
	mRenderThread->ready();
	mRenderThread->moveToThread(mRenderThread);
	connect(window(), SIGNAL(sceneGraphInvalidated()), mRenderThread, SLOT(shutDown()), Qt::QueuedConnection);

	mRenderThread->start();
    update();
}


QSGNode *OpenGLQuickItem::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    TextureNode *node = static_cast<TextureNode *>(oldNode);

	if (!mRenderThread->hasValidContext())
	{
        QOpenGLContext *current = window()->openglContext();
        // Some GL implementations requres that the currently bound context is
        // made non-current before we set up sharing, so we doneCurrent here
        // and makeCurrent down below while setting up our own context.
        current->doneCurrent();

		mRenderThread->createContext(current);

        current->makeCurrent(window());

        QMetaObject::invokeMethod(this, "ready");
        return 0;
    }

	if (!node)
	{
        node = new TextureNode(window());

        /* Set up connections to get the production of FBO textures in sync with vsync on the
         * rendering thread.
         *
         * When a new texture is ready on the rendering thread, we use a direct connection to
         * the texture node to let it know a new texture can be used. The node will then
         * emit pendingNewTexture which we bind to QQuickWindow::update to schedule a redraw.
         *
         * When the scene graph starts rendering the next frame, the prepareNode() function
         * is used to update the node with the new texture. Once it completes, it emits
         * textureInUse() which we connect to the FBO rendering thread's renderNext() to have
         * it start producing content into its current "back buffer".
         *
         * This FBO rendering pipeline is throttled by vsync on the scene graph rendering thread.
         */
		connect(mRenderThread, SIGNAL(textureReady(int,QSize)), node, SLOT(newTexture(int,QSize)), Qt::DirectConnection);
        connect(node, SIGNAL(pendingNewTexture()), window(), SLOT(update()), Qt::QueuedConnection);
        connect(window(), SIGNAL(beforeRendering()), node, SLOT(prepareNode()), Qt::DirectConnection);
		connect(node, SIGNAL(textureInUse()), mRenderThread, SLOT(renderNext()), Qt::QueuedConnection);

        // Get the production of FBO textures started..
		QMetaObject::invokeMethod(mRenderThread, "renderNext", Qt::QueuedConnection);
    }

    node->setRect(boundingRect());

    return node;
}

/*
 * Created by Dan Watkins on 2014.11.26
 * Content derived from the "Scene Graph - Rendering FBOs in a thread" example
 */

#ifndef _OPENGL_QUICK_ITEM_H
#define _OPENGL_QUICK_ITEM_H

#include <QQuickItem>

class OpenGLQuickItem : public QQuickItem
{
	Q_OBJECT

public:
	OpenGLQuickItem();
	static void cleanupRenderThreads();	//this will block until all RenderThreads can be shutdown and deleted gracefully

public slots:
	void ready();

protected:
	QSGNode *updatePaintNode(QSGNode*, UpdatePaintNodeData*);

private:
	class RenderThread;
	friend class RenderThread;
	static QList<RenderThread*> mRenderThreads;

	RenderThread *mRenderThread;
};

#endif

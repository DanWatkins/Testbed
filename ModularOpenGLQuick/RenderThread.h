/*
 * Created by Dan Watkins on 2014.11.26
 * Content derived from the "Scene Graph - Rendering FBOs in a thread" example
 */

#include "OpenGLQuickItem.h"

#include <QtCore/QThread>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QOffscreenSurface>

class OpenGLQuickItem::RenderThread : public QThread
{
	Q_OBJECT

public:
	RenderThread(const QSize &size);

	QOffscreenSurface *mSurface;
	QOpenGLContext *mContext;

public slots:
	void renderNext();
	void shutdown();

signals:
	void textureReady(int id, const QSize &size);

private:
	QOpenGLFramebufferObject *mFboRender, *mFboDisplay;
	QSize mSize;
};

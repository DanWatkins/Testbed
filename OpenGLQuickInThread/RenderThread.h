#ifndef _RENDER_THREAD_H
#define _RENDER_THREAD_H

#include <QtGui/QOpenGLFramebufferObject>
#include <QtGui/QOffscreenSurface>
#include <QtGui/QOpenGLContext>

#include <QtCore/QThread>
#include <QtCore/QMutex>

#include <QtGui/QGuiApplication>

#include "logorenderer.h"


/*
 * The render thread shares a context with the scene graph and will
 * render into two separate FBOs, one to use for display and one
 * to use for rendering
 */
class RenderThread : public QThread
{
	Q_OBJECT
public:
	RenderThread(const QSize &size);

	QOffscreenSurface *surface;
	QOpenGLContext *context;

public slots:
	void renderNext();
	void shutDown();

signals:
	void textureReady(int id, const QSize &size);

private:
	QOpenGLFramebufferObject *m_renderFbo;
	QOpenGLFramebufferObject *m_displayFbo;

	LogoRenderer *m_logoRenderer;
	QSize m_size;
};

#endif

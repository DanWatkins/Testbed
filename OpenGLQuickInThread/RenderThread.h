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

	void ready();
	void createContext(QOpenGLContext *sharedContext);

	bool hasValidContext() { return mContext != nullptr; }

public slots:
	void renderNext();
	void shutDown();

signals:
	void textureReady(int id, const QSize &size);

private:
	QOffscreenSurface *mSurface;
	QOpenGLContext *mContext;


	QOpenGLFramebufferObject *mRenderFbo;
	QOpenGLFramebufferObject *mDisplayFbo;

	LogoRenderer *mLogoRenderer;
	QSize mSize;
};

#endif

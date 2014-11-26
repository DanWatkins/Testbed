#include "Squircle.h"
#include <QtQuick/QQuickWindow>

Squircle::Squircle() :
	mT(0),
	mRenderer(nullptr)
{
	QObject::connect(this,
					 SIGNAL(windowChanged(QQuickWindow*)),
					 this,
					 SLOT(handleWindowChanged(QQuickWindow*)));
}


void Squircle::handleWindowChanged(QQuickWindow *window)
{
	if (window)
	{
		QObject::connect(window,
						 SIGNAL(beforeRendering()),
						 this,
						 SLOT(sync()),
						 Qt::DirectConnection);

		QObject::connect(window,
						 SIGNAL(sceneGraphInvalidated()),
						 this,
						 SLOT(cleanup()),
						 Qt::DirectConnection);

		window->setClearBeforeRendering(false);
	}
}

void Squircle::cleanup()
{
	if (mRenderer)
	{
		delete mRenderer;
		mRenderer = nullptr;
	}
}


void Squircle::sync()
{
	if (!mRenderer)
	{
		mRenderer = new SquircleRenderer();
		QObject::connect(window(),
						 SIGNAL(beforeRendering()),
						 mRenderer,
						 SLOT(paint()),
						 Qt::DirectConnection);
	}

	mRenderer->setViewportSize(window()->size() * window()->devicePixelRatio());
	mRenderer->setT(mT);
}


void Squircle::setT(qreal t)
{
	if (t == mT)
		return;

	mT = t;
	emit tChanged();

	if (window())
		window()->update();
}

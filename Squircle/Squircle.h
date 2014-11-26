#ifndef _SQUIRCLE_H
#define _SQUIRCLE_H

#include <QtQuick/QQuickItem>
#include "SquircleRenderer.h"

class Squircle : public QQuickItem
{
	Q_OBJECT
	Q_PROPERTY(qreal t READ t WRITE setT NOTIFY tChanged)

public:
	Squircle();

	qreal t() const { return mT; }
	void setT(qreal t);

signals:
	void tChanged();

public slots:
	void sync();
	void cleanup();

private slots:
	void handleWindowChanged(QQuickWindow *window);

private:
	qreal mT;
	SquircleRenderer *mRenderer;
};

#endif


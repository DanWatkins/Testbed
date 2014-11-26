#ifndef _SQUIRCLE_RENDERER_H
#define _SQUIRCLE_RENDERER_H

#include <QtCore>
#include <QtGui/QOpenGLShaderProgram>

class SquircleRenderer : public QObject
{
	Q_OBJECT

public:
	SquircleRenderer() : mT(0), mProgram(0) {}
	~SquircleRenderer() { if (mProgram) delete mProgram; }

	void setT(qreal t) { mT = t; }
	void setViewportSize(const QSize &size) { mViewportSize = size; }

public slots:
	void paint();

private:
	QSize mViewportSize;
	qreal mT;
	QOpenGLShaderProgram *mProgram;
};

#endif


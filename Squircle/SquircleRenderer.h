#ifndef _SQUIRCLE_RENDERER_H
#define _SQUIRCLE_RENDERER_H

#include <QtCore>
#include <QtGui/QOpenGLShaderProgram>
#include <memory>

class SquircleRenderer : public QObject
{
	Q_OBJECT

public:
	SquircleRenderer();
	~SquircleRenderer();

	void setT(qreal t);
	void setViewportSize(const QSize &size);

public slots:
	void paint();

private:
	Q_DISABLE_COPY(SquircleRenderer)
	class Renderer;
	std::unique_ptr<Renderer> imp;
};

#endif


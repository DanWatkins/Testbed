#include "SquircleRenderer.h"

void SquircleRenderer::paint()
{
	if (!mProgram)
	{
		mProgram = new QOpenGLShaderProgram();
		mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex,
										   "attribute highp vec4 vertices;"
										   "varying highp vec2 coords;"
										   "void main() {"
										   "    gl_Position = vertices;"
										   "    coords = vertices.xy;"
										   "}");
		mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment,
										   "uniform lowp float t;"
										   "varying highp vec2 coords;"
										   "void main() {"
										   "    lowp float i = 1. - (pow(abs(coords.x), 4.) + pow(abs(coords.y), 4.));"
										   "    i = smoothstep(t - 0.8, t + 0.8, i);"
										   "    i = floor(i * 20.) / 20.;"
										   "    gl_FragColor = vec4(coords * .5 + .5, i, i);"
										   "}");

		mProgram->bindAttributeLocation("vertices", 0);
		mProgram->link();
	}

	mProgram->bind();
	{
		mProgram->enableAttributeArray(0);

		float values[] = {
			-1, -1,
			1, -1,
			-1, 1,
			1, 1
		};
		mProgram->setAttributeArray(0, GL_FLOAT, values, 2);
		mProgram->setUniformValue("t", (float) mT);

		glViewport(0, 0, mViewportSize.width(), mViewportSize.height());

		glDisable(GL_DEPTH_TEST);

		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		mProgram->disableAttributeArray(0);
	}
	mProgram->release();
}

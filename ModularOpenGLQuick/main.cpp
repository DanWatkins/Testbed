/*
 * Created by Dan Watkins on 2014.11.26
 * Content derived from the "Scene Graph - Rendering FBOs in a thread" example
 */

#include <QGuiApplication>
#include <QtQuick/QQuickView>

#include "OpenGLQuickItem.h"

int main(int argc, char **argv)
{
	QGuiApplication app(argc, argv);
	qmlRegisterType<OpenGLQuickItem>("OpenGLQuickItem", 1, 0, "OpenGLScene");
	int execReturn = 0;

	{
		QQuickView view;
		view.setPersistentOpenGLContext(true);
		view.setPersistentSceneGraph(true);
		view.setResizeMode(QQuickView::SizeRootObjectToView);
		view.setSource(QUrl("qrc:/main.qml"));
		view.show();

		execReturn = app.exec();
	}

	OpenGLQuickItem::cleanupRenderThreads();

	return execReturn;
}

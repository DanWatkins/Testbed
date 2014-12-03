#include <QtCore/QThread>
#include <QGuiApplication>

#include <QtGui/private/qguiapplication_p.h>
#include <QtGui/qpa/qplatformintegration.h>
#include <QtQuick/QQuickView>

#include "../MyOpenGLQuickItem.h"

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

	if (!QGuiApplicationPrivate::platform_integration->hasCapability(QPlatformIntegration::ThreadedOpenGL))
	{
		qDebug() << "Error: Platform does not support threaded OpenGL";
		return EXIT_FAILURE;
    }

	qmlRegisterType<MyOpenGLQuickItem>("SceneGraphRendering", 1, 0, "OpenGLQuickItem");
    int execReturn = 0;

    {
        QQuickView view;

		QSurfaceFormat format;
		format.setMajorVersion(4);
		format.setMinorVersion(2);
		format.setProfile(QSurfaceFormat::CompatibilityProfile);
		view.setFormat(format);

        view.setPersistentOpenGLContext(true);
        view.setPersistentSceneGraph(true);

        view.setResizeMode(QQuickView::SizeRootObjectToView);
        view.setSource(QUrl("qrc:///scenegraph/textureinthread/main.qml"));
        view.show();

        execReturn = app.exec();
    }

	OpenGLQuickItem::endAllRenderThreads();

    return execReturn;
}

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQuick/QQuickView>
#include "Squircle.h"

int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);

	qmlRegisterType<Squircle>("OpenGLUnderQML", 1, 0, "Squircle");

	QQuickView view;
	view.setResizeMode(QQuickView::SizeRootObjectToView);
	view.setSource(QUrl(QStringLiteral("qrc:/main.qml")));
	view.show();

    return app.exec();
}

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Message.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


	QList<QObject*> dataList;
	dataList.append(new Message("Dan"));
	dataList.append(new Message("Face"));

	engine.rootContext()->setContextProperty("dataModel",
											 QVariant::fromValue(dataList));

	return app.exec();
}

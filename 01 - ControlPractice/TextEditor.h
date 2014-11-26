#ifndef TEXT_EDITOR_H
#define TEXT_EDITOR_H

#include <QObject>
#include <QFile>
#include <QDebug>

class TextEditor : public QObject
{
	Q_OBJECT

public:
	Q_INVOKABLE void saveText(const QString &text)
	{
		qDebug() << "Saving text: " << text;
	}

signals:


private:
};

#endif

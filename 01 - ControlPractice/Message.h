#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <QObject>

class Message : public QObject
{
	Q_OBJECT
	Q_PROPERTY(QString author READ author WRITE setAuthor NOTIFY authorChanged)

public:
	Message(const QString author) :
		mAuthor(author)
	{
	}

	void setAuthor(const QString &author)
	{
		mAuthor = author;
		emit authorChanged();
	}

	QString author() const
	{
		return mAuthor;
	}


signals:
	void authorChanged();

private:
	QString mAuthor;
};

#endif // DATAMODEL_H

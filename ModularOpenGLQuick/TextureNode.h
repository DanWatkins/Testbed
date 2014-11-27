/*
 * Created by Dan Watkins on 2014.11.26
 * Content derived from the "Scene Graph - Rendering FBOs in a thread" example
 */

#include <QSGSimpleTextureNode>
#include <QQuickWindow>
#include <QtCore/QMutex>

class TextureNode : public QObject, public QSGSimpleTextureNode
{
	Q_OBJECT

public:
	TextureNode(QQuickWindow *window);
	~TextureNode();

signals:
	void textureInUse();
	void pendingNewTexture();

public slots:
	void newTexture(int id, const QSize &size);
	void prepareNode();

private:
	int mId;
	QSize mSize;

	QMutex mMutex;
	QSGTexture *mTexture;
	QQuickWindow *mWindow;
};

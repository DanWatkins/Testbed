#ifndef _TEXTURE_NODE_H
#define _TEXTURE_NODE_H

#include <qsgsimpletexturenode.h>
#include <QtQuick/QQuickWindow>
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

	// This function gets called on the FBO rendering thread and will store the
	// texture id and size and schedule an update on the window.
	void newTexture(int id, const QSize &size);

	// Before the scene graph starts to render, we update to the pending texture
	void prepareNode();

private:

	int m_id;
	QSize m_size;

	QMutex m_mutex;

	QSGTexture *m_texture;
	QQuickWindow *m_window;
};

#endif
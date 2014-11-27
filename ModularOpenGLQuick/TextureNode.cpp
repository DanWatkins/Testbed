/*
 * Created by Dan Watkins on 2014.11.26
 * Content derived from the "Scene Graph - Rendering FBOs in a thread" example
 */

#include "TextureNode.h"

TextureNode::TextureNode(QQuickWindow *window) :
	mId(0),
	mSize(0,0),
	mTexture(nullptr),
	mWindow(window)
{
	mTexture = mWindow->createTextureFromId(0, QSize(1,1));
	setTexture(mTexture);
	setFiltering(QSGTexture::Linear);
}


TextureNode::~TextureNode()
{
	delete mTexture;
}


void TextureNode::newTexture(int id, const QSize &size)
{
	mMutex.lock();
	{
		mId = id;
		mSize = size;
	}
	mMutex.unlock();

	emit pendingNewTexture();
}


void TextureNode::prepareNode()
{
	int newId = 0;
	mMutex.lock();
		newId = mId;
		QSize size = mSize;
		mId = 0;
	mMutex.unlock();

	if (newId)
	{
		delete mTexture;
		mTexture = mWindow->createTextureFromId(newId, size);
		setTexture(mTexture);
		emit textureInUse();
	}
}

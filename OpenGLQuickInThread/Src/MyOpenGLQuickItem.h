#ifndef _MYOPENGLQUICKITEM_H
#define _MYOPENGLQUCIKITEM_H

#include "OpenGLQuickItem.h"
#include <QtGui/QOpenGLFunctions_4_2_Compatibility>

class MyOpenGLQuickItem : public OpenGLQuickItem
{
public:
	MyOpenGLQuickItem() :
		OpenGLQuickItem(&mMyOpenGLRenderable)
	{
	}

private:
	class MyOpenGLRenderable : public IOpenGLRenderable, protected QOpenGLFunctions_4_2_Compatibility
	{
	public:
		void init()
		{
			initializeOpenGLFunctions();
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		}


		void render()
		{
			glClear(GL_COLOR_BUFFER_BIT);
		}
	} mMyOpenGLRenderable;
};

#endif


#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>

class OpenGLGfx
{
public:
	OpenGLGfx();
	virtual ~OpenGLGfx();

	void init();
	void setProjection(GLfloat viewWidth, GLfloat viewHieght);
	void draw();
};
#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>

class OpenGLGfx
{
public:
	OpenGLGfx();
	virtual ~OpenGLGfx();

	void init();
	void setModel(GLfloat x=0.0f, GLfloat y=0.0f, GLfloat z=0.0f);
	void setProjection(GLfloat viewWidth, GLfloat viewHieght);
	void genTexture(const char *path);
	void drawCube(float x, float y, float z);
	void draw();
};
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "opengl_gfx.h"

OpenGLGfx::OpenGLGfx()
{

}

OpenGLGfx::~OpenGLGfx()
{

}

void OpenGLGfx::init()
{
	glClearColor(0.15f, 0.3f, 0.5f, 1.0f);
}

void OpenGLGfx::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
#include <Windows.h>
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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGLGfx::setProjection(GLfloat viewWidth, GLfloat viewHieght)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, viewWidth / viewHieght, 0.1f, 100.0f);
}

void OpenGLGfx::draw()
{
	// 清理深度缓存
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// 开启深度测试，不然较后画的颜色会覆盖前面的颜色
	glEnable(GL_DEPTH_TEST);
	// 以边的形式显示多边形
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLfloat zOffset = -10.0f;
	GLfloat xOffset = -3.0f;
	GLfloat yOffset = 2.0f;

	// 绘cube
	glBegin(GL_QUADS);

	glColor4ub(255, 0, 0, 255);
	glVertex3f(0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(0.5 + xOffset, -0.5 + yOffset, -0.5 + zOffset);
	glVertex3f(0.5 + xOffset, 0.5 + yOffset, -0.5 + zOffset);
	glVertex3f(0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);

	glColor4ub(0, 255, 0, 255);
	glVertex3f(-0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, 0.5 + yOffset, -0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, -0.5 + yOffset, -0.5 + zOffset);

	glColor4ub(255, 255, 0, 255);
	glVertex3f(-0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);

	glColor4ub(255, 255, 255, 255);
	glVertex3f(0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);

	glColor4ub(255, 0, 255, 255);
	glVertex3f(0.5 + xOffset, -0.5 + yOffset, -0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, -0.5 + yOffset, -0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(0.5 + xOffset, -0.5 + yOffset, 0.5 + zOffset);

	glColor4ub(0, 255, 255, 255);
	glVertex3f(0.5 + xOffset, 0.5 + yOffset, -0.5 + zOffset);
	glVertex3f(0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, 0.5 + yOffset, 0.5 + zOffset);
	glVertex3f(-0.5 + xOffset, 0.5 + yOffset, -0.5 + zOffset);
	

	glEnd();
}
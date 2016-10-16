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

	// 绘制四面体
	glBegin(GL_TRIANGLES);

	// 设置第一个三角型顶点数据
	glColor4ub(200, 0, 0, 255);
	glVertex3f(-10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(0.0f, -10.0f, 10.0f - 100.0f);

	glColor4ub(0, 0, 200, 255);
	glVertex3f(0.0f, 10.0f, 0.0f - 100.0f);

	// 设置第二个三角型顶点数据
	glColor4ub(0, 0, 200, 255);
	glVertex3f(10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(0.0f, 10.0f, 0.0f - 100.0f);

	glColor4ub(200, 0, 0, 255);
	glVertex3f(0.0f, -10.0f, 10.0f - 100.0f);

	// 设置第三个三角型顶点数据
	glColor4ub(200, 0, 0, 255);
	glVertex3f(10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(-10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 0, 200, 255);
	glVertex3f(0.0f, -10.0f, 10.0f - 100.0f);

	// 设置第四个三角型顶点数据
	glColor4ub(200, 0, 0, 255);
	glVertex3f(10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(-10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 0, 200, 255);
	glVertex3f(0.0f, 10.0f, 0.0f - 100.0f);

	glEnd();
}
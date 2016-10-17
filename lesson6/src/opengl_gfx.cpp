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
}

void OpenGLGfx::setModel(GLfloat x, GLfloat y, GLfloat z)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 平移当前矩阵
	glTranslated(x, y, z);
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

	setModel(xOffset, yOffset, zOffset);

	// 把当前操作矩阵压入栈（用于保存当前矩阵）
	glPushMatrix();

	setModel(-xOffset, yOffset, zOffset);
	// 对当前操作矩阵进行缩放
	glScalef(0.5f, 1.0f, 1.0f);
	// 对当前操作矩阵进行旋转
	glRotatef(30, 0.0f, 1.0f, 0.0f);

	glBegin(GL_QUADS);

	glColor4ub(255, 0, 0, 255);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);

	glColor4ub(0, 255, 0, 255);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glColor4ub(255, 255, 0, 255);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	glColor4ub(255, 255, 255, 255);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);

	glColor4ub(255, 0, 255, 255);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	glColor4ub(0, 255, 255, 255);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glEnd();

	// 把栈顶矩阵出栈（用于恢复之前矩阵）
	glPopMatrix();

	glBegin(GL_QUADS);

	glColor4ub(255, 0, 0, 255);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);

	glColor4ub(0, 255, 0, 255);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);

	glColor4ub(255, 255, 0, 255);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);

	glColor4ub(255, 255, 255, 255);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(0.5, 0.5, 0.5);

	glColor4ub(255, 0, 255, 255);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(0.5, -0.5, 0.5);

	glColor4ub(0, 255, 255, 255);
	glVertex3f(0.5, 0.5, -0.5);
	glVertex3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, 0.5);
	glVertex3f(-0.5, 0.5, -0.5);

	glEnd();
}
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
	glClear(GL_COLOR_BUFFER_BIT);

	glColor4ub(200, 0, 0, 255);
	glLineWidth(2.0f);

	// ����������
	glBegin(GL_TRIANGLES);

	// ���õ�һ�������Ͷ�������
	glVertex3f(-3.0f, 0.0f, -10.0f);
	glVertex3f(-5.0f, 0.0f, -10.0f);
	glVertex3f(-5.0f, 2.0f, -10.0f);

	// ���õڶ��������Ͷ�������
	glVertex3f(3.0f, 0.0f, -10.0f);
	glVertex3f(5.0f, 0.0f, -10.0f);
	glVertex3f(5.0f, 2.0f, -10.0f);

	glEnd();

	// �����ı���
	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(2.0f, 0.0f, -10.0f);
	glVertex3f(2.0f, 1.0f, -10.0f);
	glVertex3f(0.0f, 1.0f, -10.0f);
	glEnd();

	// ���ƶ����
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, -3.0f, -10.0f);
	glVertex3f(2.0f, -4.0f, -10.0f);
	glVertex3f(3.0f, -2.0f, -10.0f);
	glVertex3f(2.0f, -1.0f, -10.0f);
	glEnd();
}
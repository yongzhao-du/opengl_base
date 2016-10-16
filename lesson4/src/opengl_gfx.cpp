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
	// ������Ȼ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// ������Ȳ��ԣ���Ȼ�Ϻ󻭵���ɫ�Ḳ��ǰ�����ɫ
	glEnable(GL_DEPTH_TEST);

	// ����������
	glBegin(GL_TRIANGLES);

	// ���õ�һ�������Ͷ�������
	glColor4ub(200, 0, 0, 255);
	glVertex3f(-10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(0.0f, -10.0f, 10.0f - 100.0f);

	glColor4ub(0, 0, 200, 255);
	glVertex3f(0.0f, 10.0f, 0.0f - 100.0f);

	// ���õڶ��������Ͷ�������
	glColor4ub(0, 0, 200, 255);
	glVertex3f(10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(0.0f, 10.0f, 0.0f - 100.0f);

	glColor4ub(200, 0, 0, 255);
	glVertex3f(0.0f, -10.0f, 10.0f - 100.0f);

	// ���õ����������Ͷ�������
	glColor4ub(200, 0, 0, 255);
	glVertex3f(10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(-10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 0, 200, 255);
	glVertex3f(0.0f, -10.0f, 10.0f - 100.0f);

	// ���õ��ĸ������Ͷ�������
	glColor4ub(200, 0, 0, 255);
	glVertex3f(10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 200, 0, 255);
	glVertex3f(-10.0f, -10.0f, -10.0f - 100.0f);

	glColor4ub(0, 0, 200, 255);
	glVertex3f(0.0f, 10.0f, 0.0f - 100.0f);

	glEnd();
}
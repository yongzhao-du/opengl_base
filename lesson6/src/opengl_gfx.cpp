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

	// ƽ�Ƶ�ǰ����
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
	// ������Ȼ���
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// ������Ȳ��ԣ���Ȼ�Ϻ󻭵���ɫ�Ḳ��ǰ�����ɫ
	glEnable(GL_DEPTH_TEST);
	// �Աߵ���ʽ��ʾ�����
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	GLfloat zOffset = -10.0f;
	GLfloat xOffset = -3.0f;
	GLfloat yOffset = 2.0f;

	setModel(xOffset, yOffset, zOffset);

	// �ѵ�ǰ��������ѹ��ջ�����ڱ��浱ǰ����
	glPushMatrix();

	setModel(-xOffset, yOffset, zOffset);
	// �Ե�ǰ���������������
	glScalef(0.5f, 1.0f, 1.0f);
	// �Ե�ǰ�������������ת
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

	// ��ջ�������ջ�����ڻָ�֮ǰ����
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
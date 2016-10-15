#include <Windows.h>
#include "opengl_gfx.h"

//�ֲ����꣨ģ�;����������꣨�ӿھ����ӿ����꣨�ӿھ�����Ļ����
//opengl����ģ�;��󡱺͡��ӿھ��󡱺���һ�𣨾�����ˣ�

OpenGLGfx::OpenGLGfx()
{

}

OpenGLGfx::~OpenGLGfx()
{

}

void OpenGLGfx::init()
{
	// ���ñ�����ɫ
	glClearColor(0.15f, 0.3f, 0.5f, 1.0f);

	// ���õ�ǰ�����ľ���������ģ�;���
	glMatrixMode(GL_MODELVIEW);
	// �ѵ�ǰ������Ϊ��λ����
	glLoadIdentity();
}

void OpenGLGfx::setProjection(GLfloat viewWidth, GLfloat viewHieght)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 45.0f ��������¼н�
	// 800.0f/600.0f ��Ļ��߱�
	// 0.1f ������Ӿ���
	// 100.0f ��Զ���Ӿ���
	gluPerspective(45.0f, viewWidth / viewHieght, 0.1f, 100.0f);
}

void OpenGLGfx::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// ������ƽ��
	glEnable(GL_POINT_SMOOTH);

	// ���û�����ɫ
	glColor4ub(255, 255, 255, 255);
	// ���û��Ƶ��С
	glPointSize(20.0f);
	
	// ��ʼ���Ƶ�
	glBegin(GL_POINTS);
	// ���û������ݣ����㣩
	glVertex3f(-2.0f, 0.0f, -10.0f);
	// ��������
	glEnd();

	// ���û����߿�
	glLineWidth(2.0f);

	// ������
	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(2.0f, 0.0f, -10.0f);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex3f(-3.0f, 0.0f, -10.0f);
	glVertex3f(-5.0f, 0.0f, -10.0f);
	glVertex3f(-5.0f, 2.0f, -10.0f);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex3f(3.0f, 0.0f, -10.0f);
	glVertex3f(5.0f, 0.0f, -10.0f);
	glVertex3f(5.0f, 2.0f, -10.0f);
	glEnd();
}
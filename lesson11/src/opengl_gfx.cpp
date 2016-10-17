#include <Windows.h>
#include "opengl_gfx.h"
#include "utils.h"

OpenGLGfx::OpenGLGfx()
{

}

OpenGLGfx::~OpenGLGfx()
{

}

GLUquadric* disk;

void OpenGLGfx::init()
{
	glClearColor(0.15f, 0.3f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	
	float ambientLightColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float diffuseLightColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float specularLightColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	float lightPos[] = { 0.0f, 3.0f, -5.0f, 1.0f };
	float direction[] = { 0.0f, -1.0f, -1.0f, 1.0f };

	// ������һ����Դ��opengl 1.x �а˸���Դ����
	glEnable(GL_LIGHT0);

	// ���û����ⷢ����ɫ
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLightColor);

	// ����������ⷢ����ɫ
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLightColor);
	
	// ���õ�ⷢ����ɫ
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLightColor);

	// ���ù�Դ��λ�ã�����Ƕ�Ϊ����ĸ��������һ������Ϊ0��ʾƽ��⣬Ϊ1��ʾ˥����
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// ����̽�յƣ�30.0fΪԲ׶���
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 20.0f);
	// ����̽�յƷ���
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	// ���ð��յ�˥��
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 20.0f);

	float ambientM[] = { 0.2f, 0.0f, 0.0f, 1.0f };
	float diffuseM[] = { 0.2f, 0.0f, 0.0f, 1.0f };
	float specularM[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	// ���û�������ʷ�����ɫ
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientM);

	// ���������ʷ�����ɫ
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseM);

	// ���õ����ʷ�����ɫ
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularM);

	glMaterialf(GL_FRONT, GL_SHININESS, 30.0f);
	glEnable(GL_LIGHTING);

	disk = gluNewQuadric();
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

void OpenGLGfx::genTexture(const char *path)
{
	// ��������
	int imageWidth, imageHeight;
	unsigned char* imageData = LoadBMP(path, imageWidth, imageHeight);
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); //�󶨵�ǰ��������ͼ
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
}

void OpenGLGfx::drawCube(float x, float y, float z)
{
	GLuint cube = glGenLists(1);
	glNewList(cube, GL_COMPILE); //ֻ����
	
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glTranslatef(x, y, z);

	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, -0.5, -0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, -0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, 0.5, -0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(-0.5, -0.5, -0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(0.5, -0.5, 0.5);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(0.5, 0.5, -0.5);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-0.5, 0.5, -0.5);

	glEnd();

	glPopMatrix();

	glEndList();

	glCallList(cube);
}

void OpenGLGfx::draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	gluSphere(disk, 1.0f, 360.0f, 180.0f);

	glLoadIdentity();
	glTranslatef(2.0f, 0.0f, -10.0f);
	gluSphere(disk, 1.0f, 360.0f, 180.0f);

	glLoadIdentity();
	glTranslatef(4.0f, 0.0f, -10.0f);
	gluSphere(disk, 1.0f, 360.0f, 180.0f);

	glLoadIdentity();
	glTranslatef(-2.0f, 0.0f, -10.0f);
	gluSphere(disk, 1.0f, 360.0f, 180.0f);

	glLoadIdentity();
	glTranslatef(-4.0f, 0.0f, -10.0f);
	gluSphere(disk, 1.0f, 360.0f, 180.0f);
	
}
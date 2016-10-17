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

	// 开启哪一个光源，opengl 1.x 有八个光源可用
	glEnable(GL_LIGHT0);

	// 设置环境光发射颜色
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLightColor);

	// 设置漫反射光发射颜色
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLightColor);
	
	// 设置点光发射颜色
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularLightColor);

	// 设置光源的位置，发射角度为坐标的负数，最后一个参数为0表示平衡光，为1表示衰减光
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	// 设置探照灯，30.0f为圆锥半角
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 20.0f);
	// 设置探照灯方向
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, direction);
	// 设置按照灯衰减
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 20.0f);

	float ambientM[] = { 0.2f, 0.0f, 0.0f, 1.0f };
	float diffuseM[] = { 0.2f, 0.0f, 0.0f, 1.0f };
	float specularM[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	// 设置环境光材质反射颜色
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambientM);

	// 设置漫材质反射颜色
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseM);

	// 设置点光材质反射颜色
	glMaterialfv(GL_FRONT, GL_SPECULAR, specularM);

	glMaterialf(GL_FRONT, GL_SHININESS, 30.0f);
	glEnable(GL_LIGHTING);

	disk = gluNewQuadric();
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

void OpenGLGfx::genTexture(const char *path)
{
	// 创建纹理
	int imageWidth, imageHeight;
	unsigned char* imageData = LoadBMP(path, imageWidth, imageHeight);
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); //绑定当前操作的贴图
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, imageWidth, imageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
}

void OpenGLGfx::drawCube(float x, float y, float z)
{
	GLuint cube = glGenLists(1);
	glNewList(cube, GL_COMPILE); //只编译
	
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
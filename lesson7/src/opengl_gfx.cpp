#include <Windows.h>
#include "opengl_gfx.h"
#include "utils.h"

OpenGLGfx::OpenGLGfx()
{

}

OpenGLGfx::~OpenGLGfx()
{

}

void OpenGLGfx::init()
{
	glClearColor(0.15f, 0.3f, 0.5f, 1.0f);
	glEnable(GL_DEPTH_TEST);
	// 开启纹理
	glEnable(GL_TEXTURE_2D);
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

void OpenGLGfx::draw()
{
	// 清理深度缓存
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	GLfloat zOffset = -10.0f;
	GLfloat xOffset = -3.0f;
	GLfloat yOffset = 2.0f;

	setModel(-xOffset, -yOffset, zOffset);

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
}
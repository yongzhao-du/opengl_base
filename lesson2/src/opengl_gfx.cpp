#include <Windows.h>
#include "opengl_gfx.h"

//局部坐标（模型矩阵）世界坐标（视口矩阵）视口坐标（视口矩阵）屏幕坐标
//opengl将“模型矩阵”和“视口矩阵”合在一起（矩阵相乘）

OpenGLGfx::OpenGLGfx()
{

}

OpenGLGfx::~OpenGLGfx()
{

}

void OpenGLGfx::init()
{
	// 设置背景颜色
	glClearColor(0.15f, 0.3f, 0.5f, 1.0f);

	// 设置当前操作的矩阵，这里是模型矩阵
	glMatrixMode(GL_MODELVIEW);
	// 把当前矩阵设为单位矩阵
	glLoadIdentity();
}

void OpenGLGfx::setProjection(GLfloat viewWidth, GLfloat viewHieght)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// 45.0f 摄像机上下夹角
	// 800.0f/600.0f 屏幕宽高比
	// 0.1f 最近可视距离
	// 100.0f 最远可视距离
	gluPerspective(45.0f, viewWidth / viewHieght, 0.1f, 100.0f);
}

void OpenGLGfx::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	// 开启点平滑
	glEnable(GL_POINT_SMOOTH);

	// 设置绘制颜色
	glColor4ub(255, 255, 255, 255);
	// 设置绘制点大小
	glPointSize(20.0f);
	
	// 开始绘制点
	glBegin(GL_POINTS);
	// 设置绘制数据（顶点）
	glVertex3f(-2.0f, 0.0f, -10.0f);
	// 结束绘制
	glEnd();

	// 设置绘制线宽
	glLineWidth(2.0f);

	// 绘制线
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
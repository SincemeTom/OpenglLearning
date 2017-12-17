// LeaningOpengl.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Vertices.cpp"


/**
* 渲染回调函数
*/
void RenderScence() {
	// 清空颜色缓存
	glClear(GL_COLOR_BUFFER_BIT);
	// 交换前后缓存
	glutSwapBuffers();
}

/**
* 主函数
*/

int main(int argc, char ** argv) {

	// 初始化GLUT
	glutInit(&argc, argv);

	// 显示模式：双缓冲、RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// 窗口设置
	glutInitWindowSize(480, 320);      // 窗口尺寸
	glutInitWindowPosition(100, 100);  // 窗口位置
	glutCreateWindow("Tutorial 02");   // 窗口标题

									   // 开始渲染
	glutDisplayFunc(RenderScenceCB);

	// 检查GLEW是否就绪，必须要在GLUT初始化之后！
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	// 缓存清空后的颜色值
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// 创建顶点缓冲器
	CreateVertexBuffer();


	// 通知开始GLUT的内部循环
	glutMainLoop();

	return 0;
}


// LeaningOpengl.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Vertices.cpp"


/**
* ��Ⱦ�ص�����
*/
void RenderScence() {
	// �����ɫ����
	glClear(GL_COLOR_BUFFER_BIT);
	// ����ǰ�󻺴�
	glutSwapBuffers();
}

/**
* ������
*/

int main(int argc, char ** argv) {

	// ��ʼ��GLUT
	glutInit(&argc, argv);

	// ��ʾģʽ��˫���塢RGBA
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	// ��������
	glutInitWindowSize(480, 320);      // ���ڳߴ�
	glutInitWindowPosition(100, 100);  // ����λ��
	glutCreateWindow("Tutorial 02");   // ���ڱ���

									   // ��ʼ��Ⱦ
	glutDisplayFunc(RenderScenceCB);

	// ���GLEW�Ƿ����������Ҫ��GLUT��ʼ��֮��
	GLenum res = glewInit();
	if (res != GLEW_OK) {
		fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
		return 1;
	}

	// ������պ����ɫֵ
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	// �������㻺����
	CreateVertexBuffer();


	// ֪ͨ��ʼGLUT���ڲ�ѭ��
	glutMainLoop();

	return 0;
}


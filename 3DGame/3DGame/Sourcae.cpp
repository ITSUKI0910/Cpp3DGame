//https://qiita.com/narupo/items/0f24ad84141ce68fa757
//https://qiita.com/mechamogera/items/57793435553f0815063d
//#include <GSGame.h>
#define GLFW_INCLUDE_GLU
#include <opengl_ext.h>
#include <GLFW/glfw3.h>
//#define GLFW_EXPOSE_NATIVE_WIN32
//#define GLFW_EXPOSE_NATIVE_WGL
//#include <GL/glut.h>
//#include <GL/wglext.h>
//#include <GLFW/glfw3native.h>
//#include <iostream>
//#include <cstdlib>
//#include <string>

#pragma comment(linker, "/entry:mainCRTStartup")

static GLFWwindow* aWindow;
static int aWidth = 640;
static int aHeight = 480;
//static std::string aTitle = "Cube";
static const char aTitle = 'a';

//キューブの頂点情報
static const GLdouble aCubeVertex[][3] = {
	{ 0.0, 0.0, 0.0 },
{ 1.0, 0.0, 0.0 },
{ 1.0, 1.0, 0.0 },
{ 0.0, 1.0, 0.0 },
{ 0.0, 0.0, 1.0 },
{ 1.0, 0.0, 1.0 },
{ 1.0, 1.0, 1.0 },
{ 0.0, 1.0, 1.0 }
};
//キューブの面
static const int aCubeFace[][4] = {
	{ 0, 1, 2, 3 },
{ 1, 5, 6, 2 },
{ 5, 4, 7, 6 },
{ 4, 0, 3, 7 },
{ 4, 5, 1, 0 },
{ 3, 2, 6, 7 }
};
//キューブに対する法線ベクトル
static const GLdouble aCubeNormal[][3] = {
	{ 0.0, 0.0,-1.0 },
{ 1.0, 0.0, 0.0 },
{ 0.0, 0.0, 1.0 },
{ -1.0, 0.0, 0.0 },
{ 0.0,-1.0, 0.0 },
{ 0.0, 1.0, 0.0 }
};
//キューブの材質　高原の色と合わせて影が見える
static const GLfloat aCubeMaterial[] = { 0.8,0.2,0.2,1.0 };
//光源
static const GLfloat aLightColor[] = { 0.2,0.2,0.8,1.0 };//色
static const GLfloat aLight0pos[] = { 0.0,3.0,5.0,1.0 };//光源０の位置
static const GLfloat aLight1pos[] = { 5.0,3.0,0.0,1.0 };//光源１の位置

														//キューブを描画する関数
static void drawCube();
int main()
{
	//GLFW初期化
	if (!glfwInit())
	{
		//std::cerr << "glfwInit faild." << std::endl;
		exit(EXIT_FAILURE);
		//キューブを描画
	}
	//ウィンドウの生成
	aWindow = glfwCreateWindow(aWidth, aHeight, &aTitle, nullptr, nullptr);
	if (!aWindow)
	{
		//std::cerr << "gldwCreateWindow failed." << std::endl;
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(aWindow);
	/*OpenGLの初期化*/
	glEnable(GL_DEPTH_TEST);// デプスバッファの有効化。
	glEnable(GL_CULL_FACE);// カリングの有効化。
	glEnable(GL_LIGHTING);// ライティングの有効化。
	glEnable(GL_LIGHT0);// 光源0 を有効化。
	glEnable(GL_LIGHT1);// 光源1 を有効化。
	glCullFace(GL_FRONT);// カリング。
	glLightfv(GL_LIGHT1, GL_DIFFUSE, aLightColor);
	glLightfv(GL_LIGHT1, GL_SPECULAR, aLightColor);
	glClearColor(1, 1, 1, 1);
	/*メインループ*/
	while (!glfwWindowShouldClose(aWindow) || !GetAsyncKeyState(VK_ESCAPE) == 0)
	{
		//画面のクリア
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//変換行列の初期化
		glLoadIdentity();
		/*更新*/
		int width, height;
		//現在のウィンドウの大きさ
		glfwGetFramebufferSize(aWindow, &width, &height);
		//ビューボートの更新
		glViewport(0, 0, width, height);
		//透視投影
		gluPerspective(30.0, (double)width / (double)height, 1.0, 100.0);
		// 視点設定前の行列をすべて平行移動（視界に収める）。
		glTranslated(0.0, 0.0, -2.0);
		// 視点の設定。
		gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		// 光源の位置設定 （＊重要 視点の位置を設定した後に行う） 
		glLightfv(GL_LIGHT0, GL_POSITION, aLight0pos);
		glLightfv(GL_LIGHT1, GL_POSITION, aLight1pos);
		/* 描画 */
		drawCube();
		/* ダブルバッファのスワップとイベントのポーリング */
		glfwSwapBuffers(aWindow);
		glfwPollEvents();
	}
	//GLFW3の終了
	glfwTerminate();
	return EXIT_SUCCESS;
}
static void drawCube()
{
	// キューブの材質パラメータを設定。
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, aCubeMaterial);
	// キューブの頂点を描画。
	glBegin(GL_QUADS);
	for (size_t i = 0; i < 6; i++)
	{
		// 法線ベクトルをキューブに当てる。
		glNormal3dv(aCubeNormal[i]);
		for (size_t j = 0; j < 4; j++)
		{
			glVertex3dv(aCubeVertex[aCubeFace[i][j]]);
		}
	}
	glEnd();
}

#include "MyGame.h"
void MyGame::start()
{

}
void MyGame::update(float time)
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
void MyGame::draw(float time)
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
void MyGame::end()
{

}

#include "MyGame.h"
void MyGame::start()
{
		glEnable(GL_LIGHT0);// 光源0 を有効化。
		glEnable(GL_LIGHT1);// 光源1 を有効化。
		glCullFace(GL_FRONT);// カリング。
}

void MyGame::update(float time)
{

	//変換行列の初期化
	glLoadIdentity();
	Iinput.Update();

	// 光源の位置設定 （＊重要 視点の位置を設定した後に行う） 
	glLightfv(GL_LIGHT0, GL_POSITION, aLight0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, aLight1pos);

}
void MyGame::draw()
{
	// キューブの材質パラメータを設定。
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, aCubeMaterial);
	// キューブの頂点を描画。
	glBegin(GL_QUADS);
	//キューブフェイスの配列を読み取ってるのかな？
	for (size_t i = 0; i < 6; i++)
	{
		// 法線ベクトルをキューブに当てる。
		glNormal3dv(aCubeNormal[i]);
		for (size_t j = 0; j < 4; j++)
		{
			//何番目の点を順番道理に結ぶ
			glVertex3dv(aCubeVertex[aCubeFace[i][j]]);
		}
	}
	glEnd();
}
void MyGame::end()
{

}

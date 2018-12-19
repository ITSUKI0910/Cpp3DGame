#include "MyGame.h"
#include <GSmath.h>
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
	GLdouble a{ 0.0 };
	// 視点の設定。
	if (gsGetKeyState(GKEY_A) != 0)
	{
		X -= 0.1f;//左

	}
	if (gsGetKeyState(GKEY_D) != 0)
	{
		X += 0.1f;//右
	}
	if (gsGetKeyState(GKEY_W) != 0)
	{
		Z -= 0.1f;//前
	}
	if (gsGetKeyState(GKEY_S) != 0)
	{
		Z += 0.1f;//後ろ
	}
	if (gsGetKeyState(GKEY_SPACE) != 0)
	{
		Y += 0.1f;//後ろ
	}
	if (gsGetKeyState(GKEY_LSHIFT) != 0)
	{
		Y -= 0.1f;//後ろ
	}
	gluLookAt(
		X, //プレイヤーのＸ
		Y, //プレイヤーのＹ
		Z, //プレイヤーのＺ
		X, //視点のＸ
		Y, //視点のＹ
		Z - 1, //視点のＺ
		0.0, //プレイヤーの首を横に傾ける
		1.0, //わからんけど一定の数値で上下が逆さまになる
		0.0  //まじでわからん
	);
	//gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
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

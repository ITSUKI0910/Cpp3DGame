#include "I_Input.h"
void I_Input::Update()
{
	// 視点の設定。
	if (gsGetKeyState(GKEY_A) != 0)
	{
		_X -= 0.1f;//左
	}
	if (gsGetKeyState(GKEY_D) != 0)
	{
		_X += 0.1f;//右
	}
	if (gsGetKeyState(GKEY_W) != 0)
	{
		_Z -= 0.1f;//前
	}
	if (gsGetKeyState(GKEY_S) != 0)
	{
		_Z += 0.1f;//後ろ
	}
	if (gsGetKeyState(GKEY_SPACE) != 0)
	{
		_Y += 0.1f;//後ろ
	}
	if (gsGetKeyState(GKEY_LSHIFT) != 0)
	{
		_Y -= 0.1f;//後ろ
	}

	if (gsGetKeyState(GKEY_LEFT) != 0)
	{
		side -= 0.1f;//左
	}
	if (gsGetKeyState(GKEY_RIGHT) != 0)
	{
		side += 0.1f;//右
	}
	if (gsGetKeyState(GKEY_UP) != 0)
	{
		length += 0.1f;//前
	}
	if (gsGetKeyState(GKEY_DOWN) != 0)
	{
		length -= 0.1f;//後ろ
	}
	X = cos(side)*cos(length);
	Y = sin(length);
	Z = sin(side) *cos(length);
	gluLookAt(
		_X, //プレイヤーのＸ
		_Y, //プレイヤーのＹ
		_Z, //プレイヤーのＺ
		X + _X, //視点のＸ
		Y + _Y, //視点のＹ
		Z + _Z, //視点のＺ
		0.0, //プレイヤーの首を横に傾ける
		1.0, //わからんけど一定の数値で上下が逆さまになる
		0.0  //まじでわからん
	);
	//gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
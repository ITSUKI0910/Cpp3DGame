#include "I_Input.h"
void I_Input::Update()
{
	// ���_�̐ݒ�B
	if (gsGetKeyState(GKEY_A) != 0)
	{
		_X -= 0.1f;//��
	}
	if (gsGetKeyState(GKEY_D) != 0)
	{
		_X += 0.1f;//�E
	}
	if (gsGetKeyState(GKEY_W) != 0)
	{
		_Z -= 0.1f;//�O
	}
	if (gsGetKeyState(GKEY_S) != 0)
	{
		_Z += 0.1f;//���
	}
	if (gsGetKeyState(GKEY_SPACE) != 0)
	{
		_Y += 0.1f;//���
	}
	if (gsGetKeyState(GKEY_LSHIFT) != 0)
	{
		_Y -= 0.1f;//���
	}

	if (gsGetKeyState(GKEY_LEFT) != 0)
	{
		side -= 0.1f;//��
	}
	if (gsGetKeyState(GKEY_RIGHT) != 0)
	{
		side += 0.1f;//�E
	}
	if (gsGetKeyState(GKEY_UP) != 0)
	{
		length += 0.1f;//�O
	}
	if (gsGetKeyState(GKEY_DOWN) != 0)
	{
		length -= 0.1f;//���
	}
	X = cos(side)*cos(length);
	Y = sin(length);
	Z = sin(side) *cos(length);
	gluLookAt(
		_X, //�v���C���[�̂w
		_Y, //�v���C���[�̂x
		_Z, //�v���C���[�̂y
		X + _X, //���_�̂w
		Y + _Y, //���_�̂x
		Z + _Z, //���_�̂y
		0.0, //�v���C���[�̎�����ɌX����
		1.0, //�킩��񂯂ǈ��̐��l�ŏ㉺���t���܂ɂȂ�
		0.0  //�܂��ł킩���
	);
	//gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}
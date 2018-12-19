#include "MyGame.h"
#include <GSmath.h>
void MyGame::start()
{
		glEnable(GL_LIGHT0);// ����0 ��L�����B
		glEnable(GL_LIGHT1);// ����1 ��L�����B
		glCullFace(GL_FRONT);// �J�����O�B
}

void MyGame::update(float time)
{

	//�ϊ��s��̏�����
	glLoadIdentity();
	GLdouble a{ 0.0 };
	// ���_�̐ݒ�B
	if (gsGetKeyState(GKEY_A) != 0)
	{
		X -= 0.1f;//��

	}
	if (gsGetKeyState(GKEY_D) != 0)
	{
		X += 0.1f;//�E
	}
	if (gsGetKeyState(GKEY_W) != 0)
	{
		Z -= 0.1f;//�O
	}
	if (gsGetKeyState(GKEY_S) != 0)
	{
		Z += 0.1f;//���
	}
	if (gsGetKeyState(GKEY_SPACE) != 0)
	{
		Y += 0.1f;//���
	}
	if (gsGetKeyState(GKEY_LSHIFT) != 0)
	{
		Y -= 0.1f;//���
	}
	gluLookAt(
		X, //�v���C���[�̂w
		Y, //�v���C���[�̂x
		Z, //�v���C���[�̂y
		X, //���_�̂w
		Y, //���_�̂x
		Z - 1, //���_�̂y
		0.0, //�v���C���[�̎�����ɌX����
		1.0, //�킩��񂯂ǈ��̐��l�ŏ㉺���t���܂ɂȂ�
		0.0  //�܂��ł킩���
	);
	//gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// �����̈ʒu�ݒ� �i���d�v ���_�̈ʒu��ݒ肵����ɍs���j 
	glLightfv(GL_LIGHT0, GL_POSITION, aLight0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, aLight1pos);

}
void MyGame::draw()
{
	// �L���[�u�̍ގ��p�����[�^��ݒ�B
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, aCubeMaterial);
	// �L���[�u�̒��_��`��B
	glBegin(GL_QUADS);
	//�L���[�u�t�F�C�X�̔z���ǂݎ���Ă�̂��ȁH
	for (size_t i = 0; i < 6; i++)
	{
		// �@���x�N�g�����L���[�u�ɓ��Ă�B
		glNormal3dv(aCubeNormal[i]);
		for (size_t j = 0; j < 4; j++)
		{
			//���Ԗڂ̓_�����ԓ����Ɍ���
			glVertex3dv(aCubeVertex[aCubeFace[i][j]]);
		}
	}
	glEnd();
}
void MyGame::end()
{

}

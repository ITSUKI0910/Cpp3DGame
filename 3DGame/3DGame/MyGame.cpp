#include "MyGame.h"
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
	Iinput.Update();

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

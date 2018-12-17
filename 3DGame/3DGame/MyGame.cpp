#include "MyGame.h"
void MyGame::start()
{

}
void MyGame::update(float time)
{
	//��ʂ̃N���A
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//�ϊ��s��̏�����
	glLoadIdentity();
	/*�X�V*/
	int width, height;
	//���݂̃E�B���h�E�̑傫��
	glfwGetFramebufferSize(aWindow, &width, &height);
	//�r���[�{�[�g�̍X�V
	glViewport(0, 0, width, height);
	//�������e
	gluPerspective(30.0, (double)width / (double)height, 1.0, 100.0);
	// ���_�ݒ�O�̍s������ׂĕ��s�ړ��i���E�Ɏ��߂�j�B
	glTranslated(0.0, 0.0, -2.0);
	// ���_�̐ݒ�B
	gluLookAt(3.0, 4.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// �����̈ʒu�ݒ� �i���d�v ���_�̈ʒu��ݒ肵����ɍs���j 
	glLightfv(GL_LIGHT0, GL_POSITION, aLight0pos);
	glLightfv(GL_LIGHT1, GL_POSITION, aLight1pos);
	/* �`�� */
	drawCube();
	/* �_�u���o�b�t�@�̃X���b�v�ƃC�x���g�̃|�[�����O */
	glfwSwapBuffers(aWindow);
	glfwPollEvents();
}
void MyGame::draw(float time)
{
	// �L���[�u�̍ގ��p�����[�^��ݒ�B
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, aCubeMaterial);
	// �L���[�u�̒��_��`��B
	glBegin(GL_QUADS);
	for (size_t i = 0; i < 6; i++)
	{
		// �@���x�N�g�����L���[�u�ɓ��Ă�B
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

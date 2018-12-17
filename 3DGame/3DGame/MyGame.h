#pragma once
#include <GSgame.h>
class MyGame :public gslib::Game
{
public:
	void start() override;
	// �X�V
	void update(float time) override;
	// �`��
	void draw(float time) override;
	// �I��
	void end() override;
private:
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
	//�L���[�u�̖�
	static const int aCubeFace[][4] = {
		{ 0, 1, 2, 3 },
	{ 1, 5, 6, 2 },
	{ 5, 4, 7, 6 },
	{ 4, 0, 3, 7 },
	{ 4, 5, 1, 0 },
	{ 3, 2, 6, 7 }
	};
	//�L���[�u�ɑ΂���@���x�N�g��
	static const GLdouble aCubeNormal[][3] = {
		{ 0.0, 0.0,-1.0 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ -1.0, 0.0, 0.0 },
	{ 0.0,-1.0, 0.0 },
	{ 0.0, 1.0, 0.0 }
	};
	//�L���[�u�̍ގ��@�����̐F�ƍ��킹�ĉe��������
	static const GLfloat aCubeMaterial[] = { 0.8,0.2,0.2,1.0 };
	//����
	static const GLfloat aLightColor[] = { 0.2,0.2,0.8,1.0 };//�F
	static const GLfloat aLight0pos[] = { 0.0,3.0,5.0,1.0 };//�����O�̈ʒu
	static const GLfloat aLight1pos[] = { 5.0,3.0,0.0,1.0 };//�����P�̈ʒu
};

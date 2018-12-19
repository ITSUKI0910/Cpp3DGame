#pragma once
#include <GSgame.h>
class MyGame :public gslib::Game
{
public:
	void start() override;
	// �X�V
	void update(float time) override;
	// �`��
	void draw() override;
	// �I��
	void end() override;

private:
	 GLdouble aCubeVertex[8][3] = {
		{ 0.0, 0.0, 0.0 },
	    { 1.0, 0.0, 0.0 },
	    { 1.0, 1.0, 0.0 },
	    { 0.0, 1.0, 0.0 },
	    { 0.0, 0.0, 1.0 },
	    { 1.0, 0.0, 1.0 },
	    { 1.0, 1.0, 1.0 },
	    { 0.0, 1.0, 1.0 }
	 };
	//�L���[�u�̖� XYZ ���E�@�㉺�@�O��
	  int aCubeFace[6][4] = {
		{ 0, 1, 2, 3 },//��
	    { 1, 5, 6, 2 },//�E
	    { 5, 4, 7, 6 },//�\
	    { 4, 0, 3, 7 },//��
	    { 4, 5, 1, 0 },//��
	    { 3, 2, 6, 7 } //��
	  };
	//�L���[�u�ɑ΂���@���x�N�g��
	  GLdouble aCubeNormal[6][3] = {
	  { 0.0, 0.0,-1.0 },//��
	  { 1.0, 0.0, 0.0 },//�E
	  { 0.0, 0.0, 1.0 },//�\
	  { -1.0, 0.0, 0.0},//��
	  { 0.0,-1.0, 0.0 },//��
	  { 0.0, 1.0, 0.0 } //��
	  };
	//�L���[�u�̍ގ��@�����̐F�ƍ��킹�ĉe��������
	  GLfloat aCubeMaterial[4] = { 0.8f,0.2f,0.2f,1.0f };
	//����
	  GLfloat aLightColor[4] = { 0.2f,0.2f,0.8f,1.0f };//�F
	  GLfloat aLight0pos[4] = { 0.0f,3.0f,5.0f,1.0f };//�����O�̈ʒu
	  GLfloat aLight1pos[4] = { 5.0f,3.0f,0.0f,1.0f};//�����P�̈ʒu
	  GLfloat X{0.0f}, Y{0.0f}, Z{5.0f};


};

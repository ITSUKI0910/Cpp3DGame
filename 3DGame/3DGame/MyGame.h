#pragma once
#include <GSgame.h>
class MyGame :public gslib::Game
{
public:
	void start() override;
	// 更新
	void update(float time) override;
	// 描画
	void draw() override;
	// 終了
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
	//キューブの面
	  int aCubeFace[6][4] = {
		{ 0, 1, 2, 3 },
	    { 1, 5, 6, 2 },
	    { 5, 4, 7, 6 },
	    { 4, 0, 3, 7 },
	    { 4, 5, 1, 0 },
	    { 3, 2, 6, 7 }
	  };
	//キューブに対する法線ベクトル
	  GLdouble aCubeNormal[6][3] = {
		{ 0.0, 0.0,-1.0 },
	    { 1.0, 0.0, 0.0 },
	    { 0.0, 0.0, 1.0 },
	    { -1.0, 0.0, 0.0 },
	    { 0.0,-1.0, 0.0 },
	    { 0.0, 1.0, 0.0 }
	  };
	//キューブの材質　高原の色と合わせて影が見える
	  GLfloat aCubeMaterial[4] = { 0.8f,0.2f,0.2f,1.0f };
	//光源
	  GLfloat aLightColor[4] = { 0.2f,0.2f,0.8f,1.0f };//色
	  GLfloat aLight0pos[4] = { 0.0f,3.0f,5.0f,1.0f };//光源０の位置
	  GLfloat aLight1pos[4] = { 5.0f,3.0f,0.0f,1.0f};//光源１の位置
	  GLdouble a{ 1.0 };
};

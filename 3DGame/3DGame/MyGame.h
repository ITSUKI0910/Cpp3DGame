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
	//キューブの面 XYZ 左右　上下　前後
	  int aCubeFace[6][4] = {
		{ 0, 1, 2, 3 },//裏
	    { 1, 5, 6, 2 },//右
	    { 5, 4, 7, 6 },//表
	    { 4, 0, 3, 7 },//左
	    { 4, 5, 1, 0 },//下
	    { 3, 2, 6, 7 } //上
	  };
	//キューブに対する法線ベクトル
	  GLdouble aCubeNormal[6][3] = {
	  { 0.0, 0.0,-1.0 },//裏
	  { 1.0, 0.0, 0.0 },//右
	  { 0.0, 0.0, 1.0 },//表
	  { -1.0, 0.0, 0.0},//左
	  { 0.0,-1.0, 0.0 },//下
	  { 0.0, 1.0, 0.0 } //上
	  };
	//キューブの材質　高原の色と合わせて影が見える
	  GLfloat aCubeMaterial[4] = { 0.8f,0.2f,0.2f,1.0f };
	//光源
	  GLfloat aLightColor[4] = { 0.2f,0.2f,0.8f,1.0f };//色
	  GLfloat aLight0pos[4] = { 0.0f,3.0f,5.0f,1.0f };//光源０の位置
	  GLfloat aLight1pos[4] = { 5.0f,3.0f,0.0f,1.0f};//光源１の位置
	  GLfloat X{0.0f}, Y{0.0f}, Z{5.0f};


};

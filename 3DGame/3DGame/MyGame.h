#pragma once
#include <GSgame.h>
class MyGame :public gslib::Game
{
public:
	void start() override;
	// 更新
	void update(float time) override;
	// 描画
	void draw(float time) override;
	// 終了
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
	//キューブの面
	static const int aCubeFace[][4] = {
		{ 0, 1, 2, 3 },
	{ 1, 5, 6, 2 },
	{ 5, 4, 7, 6 },
	{ 4, 0, 3, 7 },
	{ 4, 5, 1, 0 },
	{ 3, 2, 6, 7 }
	};
	//キューブに対する法線ベクトル
	static const GLdouble aCubeNormal[][3] = {
		{ 0.0, 0.0,-1.0 },
	{ 1.0, 0.0, 0.0 },
	{ 0.0, 0.0, 1.0 },
	{ -1.0, 0.0, 0.0 },
	{ 0.0,-1.0, 0.0 },
	{ 0.0, 1.0, 0.0 }
	};
	//キューブの材質　高原の色と合わせて影が見える
	static const GLfloat aCubeMaterial[] = { 0.8,0.2,0.2,1.0 };
	//光源
	static const GLfloat aLightColor[] = { 0.2,0.2,0.8,1.0 };//色
	static const GLfloat aLight0pos[] = { 0.0,3.0,5.0,1.0 };//光源０の位置
	static const GLfloat aLight1pos[] = { 5.0,3.0,0.0,1.0 };//光源１の位置
};

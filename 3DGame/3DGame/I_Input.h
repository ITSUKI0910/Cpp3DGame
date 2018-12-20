#pragma once
#include <GSgame.h>
class I_Input
{
public:
	I_Input() {};
	void Update();
private:
	GLfloat X{ 0.0f }, Y{ 0.0f }, Z{ 0.0f };
	GLfloat _X{ 0.0f }, _Y{ 0.0f }, _Z{ 5.0f };
	GLdouble length{ 0.0 }, side{ 0.0 };
};
#pragma once
#include "Snake.h"
#include "Food.h"
class GameSence
{
public:
	GameSence();
	void run();
	//��Ӧ��Ϣ�磺�����̣�wasd
	void onMsg(const ExMessage& msg);
	void snakeEatFood();
	void endSuccess1();
	bool isSuccess1();
private:
	Snake snake;
	Food food;
};


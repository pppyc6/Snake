#include <iostream>
#include <easyx.h>
#include "Sprite.h"
#include "Snake.h"
#include "GameSence.h"
#include<ctime>
using namespace std;

GameSence::GameSence()
{
}
void GameSence::run()
{
	BeginBatchDraw(); //˫�����ͼ
	cleardevice();
	snake.draw();
	food.draw();
	snake.bodyMove();
	EndBatchDraw();
	snakeEatFood();
	//��ȡ��Ϣ
	ExMessage msg = {0};
	while (peekmessage(&msg, EX_KEY))
	{
		onMsg(msg);
	}
}
void GameSence::onMsg(const ExMessage& msg)
{
	//�ж��Ƿ��а�������
	if (msg.message == WM_KEYDOWN)
	{
		//�ж����ĸ���������
		switch (msg.vkcode)
		{
		case VK_UP:
			if (snake.dir != VK_DOWN)
				snake.dir = msg.vkcode;
			break;
		case VK_DOWN:
			if (snake.dir != VK_UP)
				snake.dir = msg.vkcode;
			break;
		case VK_LEFT:
			if (snake.dir != VK_RIGHT)
				snake.dir = msg.vkcode;
			break;
		case VK_RIGHT:
			if (snake.dir != VK_LEFT)
				snake.dir = msg.vkcode;
			break;
		default:
			break;
		}
	}
}
void GameSence::snakeEatFood()
{
	if (snake.collision(food))
	{
		//�ߵĽ�������
		snake.incrment();
		//ʳ���������
		food.changePos();
	}
}
void GameSence::endSuccess1()
{
	float x, y, a;

	for (y = 1.5; y > -1.5; y -= 0.1)
	{
		for (x = -1.5; x < 1.5; x += 0.05)
		{
			a = x * x + y * y - 1;
			cout << (a * a * a - x * x * y * y * y <= 0.0 ? '@' : ' ');
		}
		system("color 0c");
		cout << endl;
	}
	cout << "\t\t      ��ϲ�����Ѷ�ͨ�أ�" << endl;
	system("pause");
}
bool GameSence::isSuccess1()
{
	bool ret = false;

	if (food.getFoodCount() == 7)
	{
		ret = true;
	}

	return ret;
}
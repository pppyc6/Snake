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
	BeginBatchDraw(); //双缓冲绘图
	cleardevice();
	snake.draw();
	food.draw();
	snake.bodyMove();
	EndBatchDraw();
	snakeEatFood();
	//获取消息
	ExMessage msg = {0};
	while (peekmessage(&msg, EX_KEY))
	{
		onMsg(msg);
	}
}
void GameSence::onMsg(const ExMessage& msg)
{
	//判断是否有按键按下
	if (msg.message == WM_KEYDOWN)
	{
		//判断是哪个按键按下
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
		//蛇的节数增加
		snake.incrment();
		//食物随机产生
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
	cout << "\t\t      恭喜！简单难度通关！" << endl;
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
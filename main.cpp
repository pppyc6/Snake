#include <iostream>
#include <easyx.h>
#include "Sprite.h"
#include "Snake.h"
#include "GameSence.h"
using namespace std;

int main()
{
	cout << "浅浅的尝试一下贪吃蛇吧" << endl;
	cout << "输入1开始游戏" << endl;
	cout << "输入0退出游戏" << endl;
	cout << "请输入：";

	int start;

	while (true)
	{
		cin >> start;
		switch (start)
		{
		case 0:
			return 0;
		case 1:
			goto flag;
			break;
		default:
			cout << "请重新输入！" << endl;
			break;
		}
	}
	flag:
	system("cls");

	initgraph(XSIZE, YSIZE,EX_SHOWCONSOLE);
	
	//设置随机数种子
	srand(time(nullptr));

	GameSence gameSence;

	while (gameSence.isSuccess1() != true)
	{
		gameSence.run();
		Sleep(100);
	}
	closegraph();
	gameSence.endSuccess1();

	return 0;
}
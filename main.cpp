#include <iostream>
#include <easyx.h>
#include "Sprite.h"
#include "Snake.h"
#include "GameSence.h"
using namespace std;

int main()
{
	cout << "ǳǳ�ĳ���һ��̰���߰�" << endl;
	cout << "����1��ʼ��Ϸ" << endl;
	cout << "����0�˳���Ϸ" << endl;
	cout << "�����룺";

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
			cout << "���������룡" << endl;
			break;
		}
	}
	flag:
	system("cls");

	initgraph(XSIZE, YSIZE,EX_SHOWCONSOLE);
	
	//�������������
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
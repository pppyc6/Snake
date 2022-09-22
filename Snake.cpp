#include <iostream>
#include <easyx.h>
#include "Sprite.h"
#include "Snake.h"
#include "GameSence.h"
using namespace std;
Snake::Snake() :Snake(0, 0)
{
}
Snake::Snake(int x, int y) :Sprite(x, y), dir(VK_RIGHT)
{
	nodes.push_back(Sprite(20, 0));
	nodes.push_back(Sprite(10, 0));
	nodes.push_back(Sprite(0, 0));
}
void Snake::draw()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i].draw();
	}
}
void Snake::bodyMove()
{
	//身体跟着蛇头走
	for (int i = nodes.size()-1 ; i > 0; i--)
	{
		nodes[i] = nodes[i - 1];
	}
	
	//移动蛇头
	switch (dir)
	{
	case VK_UP:
		nodes[0].moveBy(0, -10);
		break;
	case VK_DOWN:
		nodes[0].moveBy(0, 10);
		break;
	case VK_LEFT:
		nodes[0].moveBy(-10, 0);
		break;
	case VK_RIGHT:
		nodes[0].moveBy(10, 0);
		break;
	default:
		break;
	}
}
bool Snake::collision(Sprite& other)
{
	return nodes[0].collision(other);
}
void Snake::incrment()
{
	nodes.push_back(Sprite());
}
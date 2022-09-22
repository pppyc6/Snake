#include <iostream>
#include <easyx.h>
#include "Sprite.h"
#include "Snake.h"
#include "GameSence.h"
using namespace std;
using namespace std;

#define LENGTH 10

Sprite::Sprite() :Sprite(0, 0) {}
Sprite::Sprite(int x, int y): m_x(x), m_y(y), m_color(RED) {}
//���ƾ���
void Sprite::draw()
{
	//������ɫ
	setfillcolor(m_color);
 
	//���ƾ���
	fillrectangle(m_x, m_y, m_x+LENGTH, m_y+LENGTH);
}
void Sprite::moveBy(int dx, int dy)
{
	m_x += dx;
	m_y += dy;
}
bool Sprite::collision(const Sprite & other)
{
	return (m_x == other.m_x && m_y == other.m_y);
}
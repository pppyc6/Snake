#include "Food.h"
#define FoodLENRH 10
#include <ctime>
Food::Food(): m_count(0)
{
	//�����������
	m_x = rand() % (XSIZE / 10) * 10;
	m_y = rand() % (YSIZE / 10) * 10;
}
void Food::draw()
{
	setfillcolor(m_color);
	solidellipse(m_x, m_y, m_x + FoodLENRH, m_y + FoodLENRH);
}
void Food::changePos()
{
	//�����������
	m_x = rand() % (XSIZE / 10) * 10;
	m_y = rand() % (YSIZE / 10) * 10;
	m_count++;
}
int Food::getFoodCount()
{
	return  m_count;
}
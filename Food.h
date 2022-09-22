#pragma once
#include "Sprite.h"
class Food :public Sprite
{
public:
	Food();
	void draw();
	void changePos();
	int getFoodCount();
private:
	int m_count;
};
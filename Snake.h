#pragma once
#include "Sprite.h"
#include <vector>
using namespace std;
class Snake:public Sprite
{
public:
	Snake();
	Snake(int x, int y);
	virtual void draw();
	void bodyMove();
	bool collision(Sprite& other);
	void incrment();

	int dir; //蛇的方向
private:
	std::vector<Sprite> nodes; //蛇的所有节点
};
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

	int dir; //�ߵķ���
private:
	std::vector<Sprite> nodes; //�ߵ����нڵ�
};
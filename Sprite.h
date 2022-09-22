#pragma once
#include <easyx.h>
#define XSIZE 640
#define YSIZE 480

class Sprite
{
public:
	Sprite();
	Sprite(int x, int y);
	virtual void draw();
	//ÒÆ¶¯
	void moveBy(int x, int y);
	//Åö×²¼ì²â
	virtual bool collision(const Sprite& sprite);
protected:
	int m_x;
	int m_y;
	COLORREF m_color;
};


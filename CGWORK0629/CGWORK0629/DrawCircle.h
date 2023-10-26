#pragma once
#include "DrawMode.h"
class DrawCircle :
    public DrawMode
{
public:
	void draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color);
private:
	int circleX = 0;
	int circleY = 0;
};


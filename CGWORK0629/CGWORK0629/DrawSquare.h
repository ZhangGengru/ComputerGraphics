#pragma once
#include "DrawMode.h"
class DrawSquare :
    public DrawMode
{
public:
	void draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color);
};


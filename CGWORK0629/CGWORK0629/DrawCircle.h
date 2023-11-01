#pragma once
#include "DrawMode.h"
class DrawCircle :
    public DrawMode
{
public:
	virtual void draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color);
private:
	int circleX = 0;
	int circleY = 0;
};


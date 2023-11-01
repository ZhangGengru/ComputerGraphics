#pragma once
#include "DrawMode.h"
class DrawSquare :
    public DrawMode
{
public:
	virtual void draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color);
};


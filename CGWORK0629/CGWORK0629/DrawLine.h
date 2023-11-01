#pragma once
#include"DrawMode.h"

using namespace std;

class DrawLine:public DrawMode
{
public:
	virtual void draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color);
};


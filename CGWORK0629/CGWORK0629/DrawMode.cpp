#include "pch.h"
#include "DrawMode.h"

void DrawMode::drag(CDC* pDC, Point oldPoint, Point newPoint, COLORREF color)
{
	pDC->SetROP2(R2_NOTXORPEN);//设置绘图模式为R2_NOTXORPEN
	this->draw(pDC, points.back(), oldPoint,color);
	this->draw(pDC, points.back(), newPoint,color);
}

void DrawMode::updata(CDC* pDC, Point point, COLORREF color)
{
	if (!isOver())
		this->draw(pDC, points.back(), point, color);
	points.push_back(point);
}


bool DrawMode::isOver()//表示是否在绘画中，如果还接受输入点的话返回false
{
	//return lastx.size() % 2 == 0;
	return points.size() % 2 == 0;
}




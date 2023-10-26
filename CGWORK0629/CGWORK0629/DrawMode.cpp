#include "pch.h"
#include "DrawMode.h"

void DrawMode::drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color)
{
	pDC->SetROP2(R2_NOTXORPEN);//设置绘图模式为R2_NOTXORPEN
	this->draw(pDC, lastx.back(), lasty.back(), oldx, oldy, color);
	this->draw(pDC, lastx.back(), lasty.back(), newx, newy, color);
	return;
}
void DrawMode::update(CDC* pDC, int x, int y, COLORREF color)
{
	if (!isOver())
	{
		this->draw(pDC, lastx.back(), lasty.back(), x, y, color);
	}
	lastx.push_back(x);
	lasty.push_back(y);
	return;
}


bool DrawMode::isOver()//表示是否在绘画中，如果还接受输入点的话返回false
{
	return lastx.size() % 2 == 0;
}
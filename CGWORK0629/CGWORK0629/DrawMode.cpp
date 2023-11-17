#include "pch.h"
#include "DrawMode.h"

void DrawMode::drag(CDC* pDC, Point oldPoint, Point newPoint, COLORREF color)
{
	pDC->SetROP2(R2_NOTXORPEN);//���û�ͼģʽΪR2_NOTXORPEN
	this->draw(pDC, points.back(), oldPoint,color);
	this->draw(pDC, points.back(), newPoint,color);
}

void DrawMode::updata(CDC* pDC, Point point, COLORREF color)
{
	if (!isOver())
		this->draw(pDC, points.back(), point, color);
	points.push_back(point);
}


bool DrawMode::isOver()//��ʾ�Ƿ��ڻ滭�У���������������Ļ�����false
{
	//return lastx.size() % 2 == 0;
	return points.size() % 2 == 0;
}




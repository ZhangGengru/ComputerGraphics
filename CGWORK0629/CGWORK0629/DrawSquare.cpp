#include "pch.h"
#include "DrawSquare.h"

void DrawSquare::draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color)
{
    //иооб
    for (int i = startPoint.x; i <= endPoint.x; i++)
    {
		pDC->SetPixel(i, startPoint.y, color);
		pDC->SetPixel(i, endPoint.y, color);
	}
	//вСср
    for (int i = startPoint.y; i <= endPoint.y; i++)
    {
		pDC->SetPixel(startPoint.x, i, color);
		pDC->SetPixel(endPoint.x, i, color);
	}
	return;
}

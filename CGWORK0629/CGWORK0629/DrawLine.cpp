#include "pch.h"
#include "DrawLine.h"

void DrawLine::draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color)
{
    double dx, dy, e, x, y;
    dx = endPoint.x - startPoint.x;
    dy = endPoint.y - startPoint.y;
    e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    dx /= e;
    dy /= e;
    x = startPoint.x;
    y = startPoint.y;
    for (int i = 1; i <= e; i++)
    {
		pDC->SetPixel((int)(x + 0.5), (int)(y + 0.5), color);
		x += dx;
		y += dy;
	}
    return;
}


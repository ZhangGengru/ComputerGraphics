#include "pch.h"
#include "DrawLine.h"

void DrawLine::draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color)
{
    //DDAËã·¨
    double dx, dy, e, x, y;
    dx = endx - startx;
    dy = endy - starty;
    e = (fabs(dx) > fabs(dy)) ? fabs(dx) : fabs(dy);
    dx /= e;
    dy /= e;
    x = startx;
    y = starty;
    for (int i = 1; i <= e; i++)
    {
		pDC->SetPixel((int)(x+0.5),(int)(y+0.5),color);
		x += dx;
		y += dy;
	}
    return;
}


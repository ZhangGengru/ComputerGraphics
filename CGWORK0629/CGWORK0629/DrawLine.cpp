#include "pch.h"
#include "DrawLine.h"

void DrawLine::drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color)
{
    pDC->SetROP2(R2_NOTXORPEN);//���õ�ǰ����ģʽΪ������ɫ
    draw(pDC, lastx.back(),lasty.back(),oldx, oldy, color);//����
    draw(pDC, lastx.back(), lasty.back(), newx, newy, color);//��������
    return ;
}

void DrawLine::update(CDC* pDC, int x, int y, COLORREF color)
{   
    if(!isOver())
        draw(pDC, lastx.back(), lasty.back(), x, y, color);
    lastx.push_back(x);
    lasty.push_back(y);
    return;
}

void DrawLine::draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color)
{
    //DDA�㷨
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

bool DrawLine::isOver()
{
    return lastx.size() % 2 == 0;
}

#include "pch.h"
#include "DrawSquare.h"

void DrawSquare::draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color)
{
    //иооб
    for (int i = startx; i <= endx; i++)
    {
        pDC->SetPixel(i, starty, color);
        pDC->SetPixel(i, endy, color);
    }
    //вСср
    for (int i = starty; i <= endy; i++)
    {
        pDC->SetPixel(startx, i, color);
        pDC->SetPixel(endx, i, color);
    }
    return;
}



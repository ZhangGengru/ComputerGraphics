#include "pch.h"
#include "DrawCircle.h"


void DrawCircle::draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color)
{
	//Bersenham»­Ô²
	int dx = endx - startx;
	int dy = endy - starty;
	double R;
	R = sqrt(dx * dx + dy * dy) / 2;
	circleX = (startx + endx) / 2;
	circleY = (starty + endy) / 2;
	int x = 0, y = R;
	int p = 3 - 2 * R;
	for (; x <= y; x++)
	{
		pDC->SetPixel(circleX + x, circleY + y,color);
		pDC->SetPixel(circleX + x, circleY - y,color);
		pDC->SetPixel(circleX - x, circleY + y, color);
		pDC->SetPixel(circleX - x, circleY - y, color);
		//........................................................
		pDC->SetPixel(circleX + y, circleY + x, color);
		pDC->SetPixel(circleX + y, circleY - x, color);
		pDC->SetPixel(circleX - y, circleY + x, color);
		pDC->SetPixel(circleX - y, circleY - x, color);
		if (p >= 0)
		{
			p += 4 * (x - y) + 10;
			y--;
		}
		else
			p += 4 * x + 6;
	}
}



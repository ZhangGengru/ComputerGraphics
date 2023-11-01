#include "pch.h"
#include "DrawCircle.h"

void DrawCircle::draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color)
{
	//Bersenham»­Ô²
	int dx = endPoint.x - startPoint.x;
	int dy = endPoint.y - startPoint.y;
	double R;
	R = sqrt(dx * dx + dy * dy) / 2;
	circleX = (startPoint.x + endPoint.x) / 2;
	circleY = (startPoint.y + endPoint.y) / 2;
	int x = 0, y = R;
	int p = 3 - 2 * R;
	for (; x <= y; x++)
	{
		pDC->SetPixel(circleX + x, circleY + y, color);
		pDC->SetPixel(circleX + x, circleY - y, color);
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

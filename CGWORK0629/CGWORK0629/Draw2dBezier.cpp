#include "pch.h"
#include "Draw2dBezier.h"
#include "DrawLine.h"

void DRAW2DBEIZER::drag(CDC* pDC, Point oldPoint, Point newPoint, COLORREF color)
{
	pDC->SetROP2(R2_NOTXORPEN);//±³¾°·´É«
	draw(pDC, points.back(), oldPoint, color);
	draw(pDC, points.back(), newPoint, color);
	return;
}

void DRAW2DBEIZER::draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color)
{
	DrawLine drawline;
	drawline.draw(pDC, startPoint, endPoint, color);
	return;
}

void DRAW2DBEIZER::updata(CDC* pDC, Point point, COLORREF color)
{
	for(int i=point.x-2;i<=point.x+2;i++)
		for(int j=point.y-2;j<=point.y+2;j++)
			pDC->SetPixel(i, j, color);
	DrawLine drawline;
	if (!points.empty())
		drawline.draw(pDC,points.back(), point, color);
	points.push_back(point);
	if (points.size() == 4)
	{
		drawline.draw(pDC, points[0], points[3], color);
		new_split_Bezier(pDC, points);
		points.clear();
	}
	return;
}

bool DRAW2DBEIZER::isOver()
{
	return points.size() % 2 == 0;
}

void DRAW2DBEIZER::new_split_Bezier(CDC* pDC, vector<Point>&P)
{
	vector<Point> R(4), Q(4);
	const double epsilon = 1;
	if (maxdistance(P) < epsilon)
	{
		pDC->MoveTo(P[0].x, P[0].y);
		pDC->LineTo(P[3].x, P[3].y);
	}
	else
	{
		for (int i = 0; i <= 3; i++)
			R[i] = P[i];
		for (int i = 0; i <= 2; i++)
		{
			Q[i] = R[0];
			for (int j = 0; j <= 2 - i; j++)
			{
				R[j].x = (R[j].x + R[j + 1].x) / 2;
				R[j].y = (R[j].y + R[j + 1].y) / 2;
			}
		}
		Q[3] = R[0];
		new_split_Bezier(pDC, Q);
		new_split_Bezier(pDC, R);
	}
}

double DRAW2DBEIZER::maxdistance(vector<Point>& P)
{
	double s1, s2, h1, h2;
	s1 = ((P[0].x - P[1].x) * (P[0].y + P[1].y)
		+ (P[1].x - P[3].x) * (P[1].y + P[3].y)
		+ (P[3].x - P[0].x) * (P[3].y + P[0].y));
	s2 = ((P[0].x - P[2].x) * (P[0].y + P[2].y)
		+ (P[2].x - P[3].x) * (P[2].y + P[3].y)
		+ (P[3].x - P[0].x) * (P[3].y + P[0].y));
	double distance = sqrt((P[0].x - P[3].x) * (P[0].x - P[3].x)
						 + (P[0].y - P[3].y) * (P[0].y - P[3].y));
	h1 = fabs(s1 / distance);
	h2 = fabs(s2 / distance);
	return max(h1, h2);
}

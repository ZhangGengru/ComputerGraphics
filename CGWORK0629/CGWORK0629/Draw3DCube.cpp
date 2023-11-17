#include "pch.h"
#include "Draw3DCube.h"
#include "DrawLine.h"
void Draw3DCube::draw(CDC* pDC)
{
	vector<CubePoint> seenPoints(8);
	for (int i = 0; i < 8; i++)
	{
		seenPoints[i].set(watchPoint.getx() + d * (points[i].getx() - watchPoint.getx()) / (points[i].getz() + d),
						  watchPoint.gety() + d * (points[i].gety() - watchPoint.gety()) / (points[i].getz() + d), 0);
	}
	for (int i = 0; i < 8; i++)
	{
		//seenPoints[i] = CubePoint(seenPoints[i].getx() + 400, seenPoints[i].gety() + 700,0);
		//seenPoints[i] = CubePoint(seenPoints[i].getx()+600, seenPoints[i].gety()+200, 0);
	}
	edges.resize(12);
	edges[0].set(seenPoints[0], seenPoints[1]);
	edges[1].set(seenPoints[1], seenPoints[2]);
	edges[2].set(seenPoints[2], seenPoints[3]);
	edges[3].set(seenPoints[3], seenPoints[0]);
	edges[4].set(seenPoints[4], seenPoints[5]);
	edges[5].set(seenPoints[5], seenPoints[6]);
	edges[6].set(seenPoints[6], seenPoints[7]);
	edges[7].set(seenPoints[7], seenPoints[4]);
	edges[8].set(seenPoints[0], seenPoints[4]);
	edges[9].set(seenPoints[1], seenPoints[5]);
	edges[10].set(seenPoints[2], seenPoints[6]);
	edges[11].set(seenPoints[3], seenPoints[7]);
	DrawLine drawLine;
	for (int i = 0; i < 12; i++)
	{
		//pDC->MoveTo(edges[i].getStart().getx(), edges[i].getStart().gety());
		//pDC->LineTo(edges[i].getEnd().getx(), edges[i].getEnd().gety());
		drawLine.draw(pDC, Point(edges[i].getStart().getx(), edges[i].getStart().gety()),
			Point(edges[i].getEnd().getx(), edges[i].getEnd().gety()), RGB(0, 0, 0));

	}
}

void Draw3DCube::draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color)
{	
}

void Draw3DCube::rotate(CDC* pDC, int center, int angle)
{
	double radian = angle * M_PI / 180;
	double x, y, z;
	if (center == X)
	{
		for (int i = 0; i < 8; i++)
		{
			y = this->points[i].gety();
			z = this->points[i].getz();
			this->points[i].setY(y * cos(radian) - z * sin(radian));
			this->points[i].setZ(y * sin(radian) + z * cos(radian));
		}
	}
	else if (center == Y)
	{
		for (int i = 0; i < 8; i++)
		{
			x = this->points[i].getx();
			z = this->points[i].getz();
			this->points[i].setX(x * cos(radian) + z * sin(radian));
			this->points[i].setZ(-x * sin(radian) + z * cos(radian));
		}
	}
	else if (center == Z)
	{
		for (int i = 0; i < 8; i++)
		{
			x = this->points[i].getx();
			y = this->points[i].gety();
			this->points[i].setX(x * cos(radian) - y * sin(radian));
			this->points[i].setY(x * sin(radian) + y * cos(radian));
		}
	}
	this->draw(pDC);
}

void Draw3DCube::move(CDC* pDC, int axis, int length)
{
	
	if (axis == X)
	{
		for (int i = 0; i < 8; i++)
			this->points[i].setX(this->points[i].getx() + length);
	}
	else if (axis == Y)
	{
		for (int i = 0; i < 8; i++)
			this->points[i].setY(this->points[i].gety() + length);
	}
	else if (axis == Z)
	{
		for (int i = 0; i < 8; i++)
			this->points[i].setZ(this->points[i].getz() + length);
	}
	this->draw(pDC);
}

void Draw3DCube::setMode(MODE m)
{
	MODE_NOW = m;
}

Draw3DCube::Draw3DCube()
{
	//µã±í
	points.resize(8);
	points[0].set(0, 0, 0);
	points[1].set(200, 0, 0);
	points[2].set(200, 200, 0);
	points[3].set(0, 200, 0);
	points[4].set(0, 0, 200);
	points[5].set(200, 0, 200);
	points[6].set(200, 200, 200);
	points[7].set(0, 200, 200);
	CRect rect;

	MODE_NOW = MODE::MOVE;

}

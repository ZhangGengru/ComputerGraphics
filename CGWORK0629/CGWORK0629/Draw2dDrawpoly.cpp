#include "pch.h"
#include "Draw2dDrawpoly.h"
#include "DrawLine.h"
#include <utility>
#include <unordered_map>

struct hash_name
{
	size_t operator()(const Point& p)const
	{
		return hash<int>()(p.x) ^ hash<int>()(p.y);
	}
};
struct equal_point
{
	bool operator()(const Point& p1, const Point& p2) const
	{
		return p1.x == p2.x && p1.y == p2.y;
	}
};
void Draw2dDrawpoly::drag(CDC* pDC, Point oldPoint, Point newPoint, COLORREF color)
{
	pDC->SetROP2(R2_NOTXORPEN);//背景反色
	draw(pDC,points.back(), oldPoint, color);
	draw(pDC, points.back(), newPoint, color);
	return;
}

void Draw2dDrawpoly::draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color)
{
	DrawLine drawline;
	drawline.draw(pDC, startPoint, endPoint, color);
	return;
}
void Draw2dDrawpoly::updata(CDC* pDC, Point point, COLORREF color)
{
	if (!isOver())
		draw(pDC, points.back(), point, color);
	points.push_back(point);
	edgecolor = color;
	maxPoint.x = max(point.x, maxPoint.x);
	maxPoint.y = max(point.y, maxPoint.y);
	minPoint.x = min(point.x, minPoint.x);
	minPoint.y = min(point.y, minPoint.y);
	return;
}


bool Draw2dDrawpoly::isOver()
{
	if (points.size() == 0)
		return true;
	return false;
}

void Draw2dDrawpoly::finish(CDC* pDC, COLORREF fillcolor)
{
	DrawLine drawline;
	drawline.draw(pDC, points.back(), points.front(), edgecolor);
	//fill_inner(pDC, fillcolor);
	EdgeMarkFill(pDC, fillcolor);
	maxPoint.x = INT_MIN;
	maxPoint.y = INT_MIN;
	minPoint.x = INT_MAX;
	minPoint.y = INT_MAX;
	points.clear();
}

int Draw2dDrawpoly::inner(Point p)
{
	int m = -1, y = 0;
	//points[points.size() - 1] = points[0];
	points.push_back(points[0]);
	for (int i = 0; i < points.size() - 1; i++)
	{
		if ((p.x < points[i].x && p.x < points[i + 1].x) ||
			(p.x >= points[i].x && p.x >= points[i + 1].x) ||
			(p.y < points[i].y && p.y < points[i + 1].y))
			continue;
		else
		{
			y = points[i].y + (p.x - points[i].x)
				* (points[i + 1].y - points[i].y) / (points[i + 1].x - points[i].x);
			if (y == p.y)
				return 1;
			if (y < p.y)
				m = m * (-1);
		}
	}
	if (m == -1)
		return 0;
	else
		return 1;

}

void Draw2dDrawpoly::fill_inner(CDC* pDC, COLORREF fillcolor)
{
	vector<Point> RemainderPoint;//待测点组
	//缩小待测点组范围
	for (int i = minPoint.x; i < maxPoint.x; i++)
		for (int j = minPoint.y; j < maxPoint.y; j++)
		{
			Point temp;
			temp.x = i;
			temp.y = j;
			//pDC->SetPixel(temp.x, temp.y, fillcolor);
			RemainderPoint.push_back(temp);
		}
	for (int i = 0; i < RemainderPoint.size(); i++)
		if (inner(RemainderPoint[i])&&zgr[RemainderPoint[i].y%10][RemainderPoint[i].x%20]==1)
			pDC->SetPixel(RemainderPoint[i].x, RemainderPoint[i].y, fillcolor);
}

void Draw2dDrawpoly::EdgeMarkFill(CDC* pDC, COLORREF fillcolor)
{
	vector<Point> RemainderPoint;//待测点组
	//缩小待测点组范围
	for (int i = minPoint.x; i <= maxPoint.x; i++)
		for (int j = minPoint.y; j <= maxPoint.y; j++)
		{
			//pDC->SetPixel(i, j, fillcolor);
			RemainderPoint.push_back(Point(i,j));
		}
	unordered_map<Point, bool, hash_name, equal_point>MASK;
	//vector<pair<Point, bool>>MASK;
	for (int i = 0; i < RemainderPoint.size(); i++)
		MASK.insert(make_pair(RemainderPoint[i],false));
	/*for (auto iter = MASK.begin(); iter != MASK.end(); iter++)
			pDC->SetPixel(iter->first.x, iter->first.y, fillcolor);*/
	Point p0, p1;//边两点
	double x, y, dx, dy, Ixs, Ixy;
	int big_y; //上顶点会多一条线
	for (int i = 0; i < points.size(); i++)
	{
		if (i != points.size() - 1)
		{
			p0 = points[i];
			p1 = points[i + 1];
			big_y = (int)(max(points[i].y, points[i + 1].y));
		}
		else
		{
			p0 = points[i];
			p1 = points[0];
			big_y = (int)(max(points[i].y, points[0].y));
		}
		if (p0.y != p1.y)//非水平边
		{
			x = p0.x;
			y = p0.y;

			dx = (p1.x - p0.x) / fabs(p1.y - p0.y);
			dy = (p1.y - p0.y) / fabs(p1.y - p0.y);
			for (int y = p0.y; y != p1.y; y += dy)
			{
				x += dx;
				Ixs = (int)(x + 0.5);
				//边标志算法
				//for(int m = Ixs;m<=maxPoint.x;m++)
				MASK[Point(Ixs, y)] = !MASK[Point(Ixs, y)];
			}
		}
	}
	//边标志算法
	/*for (auto iter = MASK.begin(); iter != MASK.end(); iter++)
		if (iter->second)
			pDC->SetPixel(iter->first.x, iter->first.y, fillcolor);*/
	//栅栏改进
	for (int y = minPoint.y; y <maxPoint.y; y++)
	{
		bool inside = false;
		for (int x = minPoint.x; x < maxPoint.x; x++)
		{
			if (MASK[Point(x, y)])
				inside = !inside;
			if (inside&&zgr[y%10][x%20])
			{
				if (y == minPoint.y)//如果是最上面的一行，不绘制
					continue;
				pDC->SetPixel(x, y, fillcolor);
			}
		}
	}

}




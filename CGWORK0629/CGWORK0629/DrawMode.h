#pragma once
#include<vector>

using namespace std;

struct Point
{
	int x;
	int y;
};

class DrawMode
{
public:
	virtual void drag(CDC* pDC, Point oldPoint, Point newPoint, COLORREF color);
	virtual void draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color)=0;
	virtual void updata(CDC* pDC, Point point, COLORREF color);
	virtual bool isOver();//判断是否结束
	//记录鼠标左键点击时的坐标
	vector<Point> points;
};


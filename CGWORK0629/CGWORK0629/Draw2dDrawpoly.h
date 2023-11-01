#pragma once
#include "DrawMode.h"
class Draw2dDrawpoly :
    public DrawMode
{
public:
	Draw2dDrawpoly()
	{
		minPoint.x = INT_MAX;
		minPoint.y = INT_MAX;
		maxPoint.x = INT_MIN;
		maxPoint.y = INT_MIN;
		edgecolor = RGB(0, 0, 0);
	}
	virtual void drag(CDC* pDC, Point oldPoint, Point newPoint, COLORREF color);
	virtual void draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color);
	virtual void updata(CDC* pDC, Point point, COLORREF color);
	bool isOver();//�ж��Ƿ����
	void finish(CDC* pDC, COLORREF fillcolor);//�������Ʋ������ɫ
	void fill_inner(CDC* pDC, COLORREF fillcolor);
	void EdgeMarkFill(CDC* pDC, COLORREF fillcolor);

private:
	//int min_x = INT_MAX, min_y = INT_MAX, max_x = INT_MIN, max_y = INT_MIN;//��¼ͼ�ε���С������������
	Point minPoint, maxPoint;
	COLORREF edgecolor;
	vector<vector<int>> zgr =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,0,1,1,0,0},
		{0,1,0,0,1,0,1,0,0,1,0,0,0,1,0,1,0,0,1,0},
		{0,1,0,0,1,0,1,0,0,0,0,0,0,1,0,1,0,1,1,0},
		{0,1,0,0,1,0,1,1,1,0,0,0,1,0,0,0,1,0,1,0},
		{0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0},
		{0,1,0,0,1,0,1,0,0,1,0,1,0,0,0,0,0,0,1,0},
		{0,0,1,1,0,0,0,1,1,0,0,1,1,1,0,0,0,0,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	int inner(Point p);
};


#pragma once
#include "DrawMode.h"


class DRAW2DBEIZER :public DrawMode
{
public:
	virtual void drag(CDC* pDC, Point oldPoint, Point newPoint, COLORREF color);
	virtual void draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color);
	virtual void updata(CDC* pDC, Point point, COLORREF color);
	virtual bool isOver();//≈–∂œ «∑ÒΩ· ¯
private:
	void new_split_Bezier(CDC* pDC, vector<Point>&P);
	double maxdistance(vector<Point>& P);
};
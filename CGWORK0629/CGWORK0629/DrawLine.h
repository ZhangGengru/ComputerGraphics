#pragma once
#include"DrawMode.h"

using namespace std;

class DrawLine:public DrawMode
{
public:
	void drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color);//ÏðÆ¤Ïß
	void update(CDC* pDC, int x, int y, COLORREF color);
	void draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color);//»­Ö±Ïß
	bool isOver();
};


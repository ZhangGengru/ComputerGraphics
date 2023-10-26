#pragma once
#include"DrawMode.h"

using namespace std;

class DrawLine:public DrawMode
{
public:
	void draw(CDC* pDC, int startx, int starty, int endx, int endy, COLORREF color);//»­Ö±Ïß
};


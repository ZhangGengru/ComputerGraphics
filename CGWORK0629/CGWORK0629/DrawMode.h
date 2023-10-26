#pragma once
#include<vector>

using namespace std;
class DrawMode
{
public:
	virtual void drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color);//鼠标左键拖动时绘制图形
	virtual void update(CDC* pDC, int x, int y, COLORREF color);//鼠标左键点击时更新点的坐标
	virtual void draw(CDC* pDC,int startx,int starty,int endx,int endy,COLORREF color) = 0;//绘制图形
	virtual bool isOver();//判断是否结束
	//记录鼠标左键点击时的坐标
	vector<int>lastx;
	vector<int>lasty;
};


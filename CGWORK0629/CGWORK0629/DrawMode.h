#pragma once
#include<vector>

using namespace std;
class DrawMode
{
public:
	virtual void drag(CDC* pDC, int oldx, int oldy, int newx, int newy, COLORREF color) = 0;//�������϶�ʱ����ͼ��
	virtual void update(CDC*pDC,int x, int y,COLORREF color) = 0;//���������ʱ���µ������
	virtual void draw(CDC* pDC,int startx,int starty,int endx,int endy,COLORREF color) = 0;//����ͼ��
	virtual bool isOver() = 0;//�ж��Ƿ����
	//��¼���������ʱ������
	vector<int>lastx;
	vector<int>lasty;
};


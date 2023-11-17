#pragma once
#define M_PI       3.14159265358979323846   // pi
#include "DrawMode.h"
class CubePoint
{
public:
	CubePoint(const double x, const double y, const double z) :x(x), y(y), z(z) {};
	CubePoint() = default;
	void set(const double x, const double y, const double z) { this->x = x; this->y = y; this->z = z; }
	void setX(const double x) { this->x = x; }
	void setY(const double y) { this->y = y; }
	void setZ(const double z) { this->z = z; }
	double getx() { return x; };
	double gety() { return y; };
	double getz() { return z; };
private:
	double x;
	double y;
	double z;
};
class Edge
{
public:
	Edge() = default;
	Edge(CubePoint start,CubePoint end) :start(start), end(end) {};
	void set(CubePoint start, CubePoint end) { this->start = start; this->end = end; }
	CubePoint getStart() { return start; }
	CubePoint getEnd() { return end; }
private:
	CubePoint start;
	CubePoint end;
};
//struct Face
//{
//	Face(Point p1, Point p2, Point p3, Point p4):p1(p1),p2(p2),p3(p3),p4(p4) {};
//	Point p1;
//	Point p2;
//	Point p3;
//	Point p4;
//};
class Draw3DCube :
    public DrawMode
{
public:
	Draw3DCube();
	void draw(CDC* pDC);
	void draw(CDC* pDC, Point startPoint, Point endPoint, COLORREF color);//单纯重写
	enum XYZ { X, Y, Z };//指示旋转、平移的中心
	enum class MODE { ROTATE, MOVE };
	MODE MODE_NOW;
	void rotate(CDC* pDC, int center, int angle);
	void move(CDC* pDC, int axis, int lenght);
	void setMode(MODE m);
	vector<CubePoint> points;
	vector<Edge> edges;
	//vector<Face&> faces;
private:
	const double d = 500;
	CubePoint watchPoint = { 400.0,400.0,-d };


};


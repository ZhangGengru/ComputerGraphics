
// CGWORK0629View.cpp: CCGWORK0629View 类的实现
//
#include<typeinfo>
#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CGWORK0629.h"
#endif

#include "CGWORK0629Doc.h"
#include "CGWORK0629View.h"
#include"SetColor.h"
#include"SetFillColor.h"
#include"DrawMode.h"
#include"DrawLine.h"
#include"DrawSquare.h"
#include"DrawCircle.h"
#include"Draw2dDrawpoly.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <typeindex>

// CCGWORK0629View

IMPLEMENT_DYNCREATE(CCGWORK0629View, CView)

BEGIN_MESSAGE_MAP(CCGWORK0629View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SETCOLOR, &CCGWORK0629View::OnSetcolor)
	ON_COMMAND(ID_DRAW2D_DRAWLINE, &CCGWORK0629View::OnDraw2d_DRAWLine)
	ON_COMMAND(ID_DRAW2D_DRAWSQUARE, &CCGWORK0629View::OnDraw2dDrawsquqre)
	ON_COMMAND(ID_DRAW2D_DRAWCIRCLE,&CCGWORK0629View::OnDraw2dDrawCircle)
	ON_COMMAND(ID_DRAW2D_DRAWSQUQRE, &CCGWORK0629View::OnDraw2dDrawsquqre)
	ON_COMMAND(ID_DRAW2D_DRAWCIRCLE, &CCGWORK0629View::OnDraw2dDrawCircle)
	ON_COMMAND(ID_CLEAR, &CCGWORK0629View::OnClear)
	ON_COMMAND(ID_DRAW2D_DRAWPOLY, &CCGWORK0629View::OnDraw2dDrawpoly)
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_SETFILLCOLOR, &CCGWORK0629View::OnSetfillcolor)
END_MESSAGE_MAP()

// CCGWORK0629View 构造/析构

CCGWORK0629View::CCGWORK0629View() noexcept
{
	// TODO: 在此处添加构造代码
	r = 0;
	g = 0;
	b = 0;
	fill_b = 0;
	fill_g = 0;
	fill_r = 0;
    drawmode = new DrawLine();
	lastx = 0;
	lasty = 0;
	haslate = false;
	drag.x = 0;
	drag.y = 0;
}

CCGWORK0629View::~CCGWORK0629View()
{
	delete drawmode;
}

BOOL CCGWORK0629View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

//清屏函数
void CCGWORK0629View::clear()
{
	CDC* pDC = this->GetDC();
	CRect rect;
	GetClientRect(&rect);
	CBrush brush(RGB(255, 255, 255));
	pDC->FillRect(&rect, &brush);
}
// CCGWORK0629View 绘图

void CCGWORK0629View::OnDraw(CDC* /*pDC*/)
{
	CCGWORK0629Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CCGWORK0629View 打印

BOOL CCGWORK0629View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CCGWORK0629View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CCGWORK0629View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CCGWORK0629View 诊断

#ifdef _DEBUG
void CCGWORK0629View::AssertValid() const
{
	CView::AssertValid();
}

void CCGWORK0629View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGWORK0629Doc* CCGWORK0629View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGWORK0629Doc)));
	return (CCGWORK0629Doc*)m_pDocument;
}
#endif //_DEBUG


// CCGWORK0629View 消息处理程序

COLORREF CCGWORK0629View::currColor()
{
	return RGB(r, g, b);
}

COLORREF CCGWORK0629View::currFillColor()
{
	return RGB(fill_r, fill_g, fill_b);
}

void CCGWORK0629View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//drawmode->update(this->GetDC(), point.x, point.y, currColor());
	Point temp;
	temp.x = point.x;
	temp.y = point.y;
	drawmode->updata(this->GetDC(), temp, currColor());
	CView::OnLButtonDown(nFlags, point);
}



void CCGWORK0629View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Point temp;
	temp.x = point.x;
	temp.y = point.y;
	if (!drawmode->isOver())
	{
		CDC* pDC = this->GetDC();
		drawmode->drag(pDC, drag,temp,currColor());
	}
	drag.x = point.x;
	drag.y = point.y;
	CView::OnMouseMove(nFlags, point);
}



void CCGWORK0629View::OnSetcolor()
{
	// TODO: 在此添加命令处理程序代码
	SetColor dia;	//构造对话框对象
		//将当前颜色传递给对话框
		dia.m_b = b;
		dia.m_g = g;
		dia.m_r = r;
		//显示对话框
		if (dia.DoModal() == IDOK)
		{
			//如果用户单击了确定按钮
			b = dia.m_b;
			g = dia.m_g;
			r = dia.m_r;
			//更新颜色
		}
		return;
}
void CCGWORK0629View::OnSetfillcolor()
{
	// TODO: 在此添加命令处理程序代码
	SetFillColor dia;	//构造对话框对象
	//将当前颜色传递给对话框
	dia.m_b = fill_b;
	dia.m_g = fill_g;
	dia.m_r = fill_r;
	if (dia.DoModal() == IDOK)
	{
		fill_b = dia.m_b;
		fill_g = dia.m_g;
		fill_r = dia.m_r;
	}
	return;
}
//画线
void CCGWORK0629View::OnDraw2d_DRAWLine()
{
	delete this->drawmode;
	this->drawmode = new DrawLine();
	clear();
}

//画矩形
void CCGWORK0629View::OnDraw2dDrawsquqre()
{
	// TODO: 在此添加命令处理程序代码
	delete this->drawmode;
	this->drawmode = new DrawSquare();
	clear();
}


void CCGWORK0629View::OnDraw2dDrawCircle()
{
	// TODO: 在此添加命令处理程序代码
	delete this->drawmode;
	this->drawmode = new DrawCircle();
	clear();
}

void CCGWORK0629View::OnDraw2dDrawpoly()
{
	// TODO: 在此添加命令处理程序代码
	delete this->drawmode;
	this->drawmode = new Draw2dDrawpoly();
	clear();
}

void CCGWORK0629View::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	clear();
}

void CCGWORK0629View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	Draw2dDrawpoly tmp;
	Draw2dDrawpoly* p;
	type_index tmp_type = type_index(typeid(tmp));
	type_index dm_type = type_index(typeid(*this->drawmode));
	CDC* pDC = this->GetDC();
	if (tmp_type == dm_type)
	{
		p = (Draw2dDrawpoly*)this->drawmode;
		p->finish(pDC, currFillColor());
	}
	CView::OnRButtonDown(nFlags, point);
}




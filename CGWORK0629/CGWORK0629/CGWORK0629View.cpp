
// CGWORK0629View.cpp: CCGWORK0629View 类的实现
//

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
#include"DrawLine.h"
#include"DrawSquare.h"
#include"DrawCircle.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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
END_MESSAGE_MAP()

// CCGWORK0629View 构造/析构

CCGWORK0629View::CCGWORK0629View() noexcept
{
	// TODO: 在此处添加构造代码
	r = 0;
	g = 0;
	b = 0;
    drawmode = new DrawLine();
	lastx = 0;
	lasty = 0;
	haslate = false;
	dragx = 0;
	dragy = 0;
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

void CCGWORK0629View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	drawmode->update(this->GetDC(), point.x, point.y, currColor());
	CView::OnLButtonDown(nFlags, point);
}



void CCGWORK0629View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (!drawmode->isOver())
	{
		CDC* pDC = this->GetDC();
		drawmode->drag(pDC, dragx, dragy, point.x, point.y, currColor());
	}
	dragx = point.x;
	dragy = point.y;
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


void CCGWORK0629View::OnClear()
{
	// TODO: 在此添加命令处理程序代码
	clear();
}

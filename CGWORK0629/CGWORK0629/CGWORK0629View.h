#include"DrawMode.h"
#include"Draw3DCube.h"
// CGWORK0629View.h: CCGWORK0629View 类的接口
//

#pragma once


class CCGWORK0629View : public CView
{
protected: // 仅从序列化创建
	CCGWORK0629View() noexcept;
	DECLARE_DYNCREATE(CCGWORK0629View)

// 特性
public:
	CCGWORK0629Doc* GetDocument() const;
	int r, g, b;
	int fill_r, fill_g, fill_b;
// 操作
public:
	void clear();
// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CCGWORK0629View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetcolor();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnDraw2d_DRAWLine();
	//void setLastPoint(int x, int y);
	COLORREF currColor();
	COLORREF currFillColor();
	DrawMode* drawmode;
	int lastx;
	int lasty;
	bool haslate;
	Point drag;
	Draw3DCube::XYZ center;
	int move_step;
	int rotate_angle;
	CDC* sDC;

	afx_msg void OnDraw2dDrawsquqre();
	afx_msg void OnDraw2dDrawCircle();
	afx_msg void OnClear();
	afx_msg void OnDraw2dDrawpoly();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnSetfillcolor();
	//afx_msg void OnDraw2dBezier();
	afx_msg void OnDraw2DBezier();
	afx_msg void OnDraw3dCube();
	afx_msg void OnMoveX();
	afx_msg void OnMoveY();
	afx_msg void OnMoveZ();
	afx_msg void OnRotateX();
	afx_msg void OnRotateY();
	afx_msg void OnRotateZ();
	afx_msg void OnSetPar();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#ifndef _DEBUG  // CGWORK0629View.cpp 中的调试版本
inline CCGWORK0629Doc* CCGWORK0629View::GetDocument() const
   { return reinterpret_cast<CCGWORK0629Doc*>(m_pDocument); }
#endif


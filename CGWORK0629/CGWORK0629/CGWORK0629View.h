#include"DrawMode.h"
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
	DrawMode* drawmode;
	int lastx;
	int lasty;
	bool haslate;
	int dragx;
	int dragy;


	
	afx_msg void OnDraw2dDrawsquqre();
	afx_msg void OnDraw2dDrawCircle();
	afx_msg void OnClear();
};

#ifndef _DEBUG  // CGWORK0629View.cpp 中的调试版本
inline CCGWORK0629Doc* CCGWORK0629View::GetDocument() const
   { return reinterpret_cast<CCGWORK0629Doc*>(m_pDocument); }
#endif


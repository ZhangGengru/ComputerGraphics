#pragma once
#include "afxdialogex.h"


// SetFillColor 对话框

class SetFillColor : public CDialog
{
	DECLARE_DYNAMIC(SetFillColor)

public:
	SetFillColor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetFillColor();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETFILLCOLOR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_b;
	int m_g;
	int m_r;
};

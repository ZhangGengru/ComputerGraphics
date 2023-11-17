#pragma once
#include "afxdialogex.h"


// SetPar 对话框

class SetPar : public CDialog
{
	DECLARE_DYNAMIC(SetPar)

public:
	SetPar(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SetPar();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SETPAR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	int step;
	int angle;
};

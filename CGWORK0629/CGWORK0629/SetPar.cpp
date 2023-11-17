// SetPar.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0629.h"
#include "afxdialogex.h"
#include "SetPar.h"


// SetPar 对话框

IMPLEMENT_DYNAMIC(SetPar, CDialog)

SetPar::SetPar(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_SETPAR, pParent)
{
	angle = 0;
	angle = 0;
}

SetPar::~SetPar()
{
}

void SetPar::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, step);
	DDX_Text(pDX, IDC_EDIT2, angle);
}


BEGIN_MESSAGE_MAP(SetPar, CDialog)
END_MESSAGE_MAP()


// SetPar 消息处理程序

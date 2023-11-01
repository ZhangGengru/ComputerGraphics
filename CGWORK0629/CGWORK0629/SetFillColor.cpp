// SetFillColor.cpp: 实现文件
//

#include "pch.h"
#include "CGWORK0629.h"
#include "afxdialogex.h"
#include "SetFillColor.h"


// SetFillColor 对话框

IMPLEMENT_DYNAMIC(SetFillColor, CDialog)

SetFillColor::SetFillColor(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SETFILLCOLOR, pParent)
	, m_b(0)
	, m_g(0)
	, m_r(0)
{

}

SetFillColor::~SetFillColor()
{
}

void SetFillColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_B, m_b);
	DDX_Text(pDX, IDC_G, m_g);
	DDX_Text(pDX, IDC_R, m_r);
}


BEGIN_MESSAGE_MAP(SetFillColor, CDialog)
END_MESSAGE_MAP()


// SetFillColor 消息处理程序

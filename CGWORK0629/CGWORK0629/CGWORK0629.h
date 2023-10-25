
// CGWORK0629.h: CGWORK0629 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含 'pch.h' 以生成 PCH"
#endif

#include "resource.h"       // 主符号


// CCGWORK0629App:
// 有关此类的实现，请参阅 CGWORK0629.cpp
//

class CCGWORK0629App : public CWinApp
{
public:
	CCGWORK0629App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCGWORK0629App theApp;

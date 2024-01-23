
// DocView.h: основной файл заголовка для приложения DocView
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CDocViewApp:
// Сведения о реализации этого класса: DocView.cpp
//

class CDocViewApp : public CWinApp
{
public:
	CDocViewApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDocViewApp theApp;

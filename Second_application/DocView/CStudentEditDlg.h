#pragma once
#include "afxdialogex.h"


// Диалоговое окно CStudentEditDlg

class CStudentEditDlg : public CDialog
{
	DECLARE_DYNAMIC(CStudentEditDlg)

public:
	CStudentEditDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CStudentEditDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_STUDENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	float m_fMark;
};

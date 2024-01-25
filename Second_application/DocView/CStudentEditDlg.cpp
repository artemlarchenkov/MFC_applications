// CStudentEditDlg.cpp: файл реализации
//

#include "pch.h"
#include "DocView.h"
#include "afxdialogex.h"
#include "CStudentEditDlg.h"


// Диалоговое окно CStudentEditDlg

IMPLEMENT_DYNAMIC(CStudentEditDlg, CDialog)

CStudentEditDlg::CStudentEditDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_STUDENT, pParent)
	, m_strName(_T(""))
	, m_fMark(0)
{

}

CStudentEditDlg::~CStudentEditDlg()
{
}

void CStudentEditDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_MARK, m_fMark);
}


BEGIN_MESSAGE_MAP(CStudentEditDlg, CDialog)
END_MESSAGE_MAP()


// Обработчики сообщений CStudentEditDlg

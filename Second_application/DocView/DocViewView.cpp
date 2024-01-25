
// DocViewView.cpp: реализация класса CDocViewView
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "DocView.h"
#endif

#include "DocViewDoc.h"
#include "DocViewView.h"

#include "CStudentEditDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDocViewView

IMPLEMENT_DYNCREATE(CDocViewView, CListView)

BEGIN_MESSAGE_MAP(CDocViewView, CListView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CListView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CListView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_COMMAND(ID_MODIFY_ADD, OnAdd)
	ON_COMMAND(ID_MODIFY_DELETE, OnDelete)
	ON_UPDATE_COMMAND_UI(ID_MODIFY_DELETE, OnUpdateDelete)
END_MESSAGE_MAP()

// Создание или уничтожение CDocViewView

CDocViewView::CDocViewView() noexcept
{
	// TODO: добавьте код создания

}

CDocViewView::~CDocViewView()
{
}

BOOL CDocViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CListView::PreCreateWindow(cs);
}


void CDocViewView::OnDraw(CDC* /*pDC*/)
{
	CDocViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: добавьте здесь код отрисовки для собственных данных
}


void CDocViewView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	GetListCtrl().DeleteAllItems();

	FillList();

	// TODO: ListView можно заполнить элементами посредством непосредственного обращения
	//  к элементам управления этого списка через вызов GetListCtr().
}


// Печать CDocViewView

BOOL CDocViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CDocViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CDocViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// Диагностика CDocViewView

#ifdef _DEBUG
void CDocViewView::AssertValid() const
{
	CListView::AssertValid();
}

void CDocViewView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

void CDocViewView::FillList()
{
	CListCtrl& rList = GetListCtrl();

	rList.DeleteAllItems();

	Student* st = GetDocument()->m_list.GetFirst();

	for(; st != NULL; st = GetDocument()->m_list.GetNext())
	{
		int nPos = rList.InsertItem(rList.GetItemCount(), 
			st->GetName(), 0);
		
		CString sMark;
		sMark.Format(L"%g", st->GetMark());
		rList.SetItemText(nPos, 1, sMark);
		rList.SetItemData(nPos, (DWORD_PTR) st);
	}

}

CDocViewDoc* CDocViewView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDocViewDoc)));
	return (CDocViewDoc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CDocViewView


int CDocViewView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;
	ModifyStyle(LVS_TYPEMASK, LVS_REPORT);
	GetListCtrl().InsertColumn(0, L"Name", LVCFMT_LEFT, 150);
	GetListCtrl().InsertColumn(0, L"Mark", LVCFMT_LEFT, 150);

	// TODO:  Добавьте специализированный код создания

	return 0;
}

void CDocViewView::OnAdd()
{
	CStudentEditDlg dlg;

	if (IDOK == dlg.DoModal())
	{
		Student st;

		st.SetName(dlg.m_strName);
		st.SetMark(dlg.m_fMark);

		GetDocument()->m_list.PushBack(&st);

		GetDocument()->SetModifiedFlag(TRUE);

		GetDocument()->UpdateAllViews(NULL,
			UPDATE_ADD_STUDENT, NULL);

		FillList();


	}
}

void CDocViewView::OnDelete()
{
	if (IDYES != MessageBox(L"Удалить студента?", L"Подтверждение",
		MB_YESNO | MB_ICONQUESTION))
	{
		return;
	}

	CListCtrl& rList = GetListCtrl();

	POSITION pos = rList.GetFirstSelectedItemPosition();

	while (pos)
	{
		int nItem = rList.GetNextSelectedItem(pos);

		Student* st = GetDocument()->m_list.GetFirst();

		while (st != NULL)
		{
			if (st == (Student*) rList.GetItemData(nItem))
			{
				GetDocument()->m_list.RemoveCurrent();
				break;
			}
			st = GetDocument()->m_list.GetNext();
		}
	}
	GetDocument()->SetModifiedFlag(TRUE);
	GetDocument()->UpdateAllViews(NULL,UPDATE_DEL_STUDENT, NULL );
}

void CDocViewView::OnUpdateDelete(CCmdUI* pCmdUI)
{
	BOOL bEnable = FALSE;
	if (GetListCtrl().GetSelectedCount() > 0)
		bEnable = TRUE;

	pCmdUI->Enable(bEnable);	
}


void CDocViewView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	FillList();
}

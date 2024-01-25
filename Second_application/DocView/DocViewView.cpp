
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
	AfxMessageBox(L"OnAdd()");
}

void CDocViewView::OnDelete()
{
	AfxMessageBox(L"OnDelete()");
}

void CDocViewView::OnUpdateDelete(CCmdUI* pCmdUI)
{
}

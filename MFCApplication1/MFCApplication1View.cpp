
// MFCApplication1View.cpp: реализация класса CMFCApplication1View
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFCApplication1.h"
#endif

#include "MFCApplication1Doc.h"
#include "MFCApplication1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1View

IMPLEMENT_DYNCREATE(CMFCApplication1View, CScrollView)

BEGIN_MESSAGE_MAP(CMFCApplication1View, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Создание или уничтожение CMFCApplication1View

CMFCApplication1View::CMFCApplication1View() noexcept
{
	// TODO: добавьте код создания

}

CMFCApplication1View::~CMFCApplication1View()
{
}

BOOL CMFCApplication1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

// Рисование CMFCApplication1View

void CMFCApplication1View::OnDraw(CDC* pDC)
{
	CMFCApplication1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	CPen pen(PS_SOLID, 3, RGB(0, 0, 192));
	CPen* pOldPen = pDC->SelectObject(&pen);
	bool bFirst = true;
	for (auto& p : pDoc->m_Points)
	{
		CString s;
		s.Format(_T("[%d, %d]"), p.x, p.y);
		pDC->TextOut(p.x, p.y, s);
		pDC->SetTextColor(RGB(0, 0, 255));
		pDC->SetBkColor(RGB(255, 0, 0));
		if (bFirst)
		{
			pDC->MoveTo(p);
			bFirst = false;
		}
		else {
			pDC->LineTo(p);
		}
	}


	
}

void CMFCApplication1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: рассчитайте полный размер этого представления
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Диагностика CMFCApplication1View

#ifdef _DEBUG
void CMFCApplication1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCApplication1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCApplication1Doc* CMFCApplication1View::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication1Doc)));
	return (CMFCApplication1Doc*)m_pDocument;
}
#endif //_DEBUG


// Обработчики сообщений CMFCApplication1View


void CMFCApplication1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	GetDocument()->m_Points.push_back(point);
	GetDocument()->SetModifiedFlag();
	Invalidate();
}

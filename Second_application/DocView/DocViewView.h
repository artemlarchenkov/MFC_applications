
// DocViewView.h: интерфейс класса CDocViewView
//

#pragma once


class CDocViewView : public CListView
{
protected: // создать только из сериализации
	CDocViewView() noexcept;
	DECLARE_DYNCREATE(CDocViewView)

// Атрибуты
public:
	CDocViewDoc* GetDocument() const;

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // вызывается в первый раз после конструктора
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CDocViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	void FillList();

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAdd();
	afx_msg void OnDelete();
	afx_msg void OnUpdateDelete(CCmdUI *pCmdUI);
};

#ifndef _DEBUG  // версия отладки в DocViewView.cpp
inline CDocViewDoc* CDocViewView::GetDocument() const
   { return reinterpret_cast<CDocViewDoc*>(m_pDocument); }
#endif


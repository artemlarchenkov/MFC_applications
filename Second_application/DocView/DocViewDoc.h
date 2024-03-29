﻿
// DocViewDoc.h: интерфейс класса CDocViewDoc 
//


#pragma once
 
#include "list.h"

#define UPDATE_ADD_STUDENT 1
#define UPDATE_DEL_STUDENT 2
#define UPDATE_EDIT_STUDENT 3

class CDocViewDoc : public CDocument
{
protected: // создать только из сериализации
	CDocViewDoc() noexcept;
	DECLARE_DYNCREATE(CDocViewDoc)

// Атрибуты
public: 
	List m_list;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CDocViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual void DeleteContents();
};

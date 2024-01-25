#pragma once

class Student
{
public:
	Student()
	{
		_number = 0;
		_avgMark = 0;
	}

	~Student()
	{

	}

	Student& operator=(Student& rhv)
	{
		_name = rhv._name;


		_number = rhv._number;
		_avgMark = rhv._avgMark;

			return *this;
	}

	void SetName(CString name)
	{
		_name = name;

	}

	CString GetName()
	{
		return _name;
	}

	void SetNumber(int n)
	{
		if (n > 0)
			_number = n;
	}
	
	int GetNumber()
	{
		return _number;
	}

	void SetMark(float mark)
	{
		if (mark >= 0.0 && mark <= 100.0)
		{
			_avgMark = mark;
		}
	}

	float GetMark()
	{
		return _avgMark;
	}

private:
		int _number;
		CString _name;
		float _avgMark;
};

class List
{
	struct ListNode
	{
		Student s;
		ListNode* next;
	};
public:
	List()
	{
		_first = _cur = NULL;
	}
	List(List& src)
	{
		CopyFrom(src);
	}
	~List()
	{
		Clear();
	}

	void Clear()
	{
		ListNode* node = _first;

		while (node != NULL)
		{
			ListNode* tmp = node;
			node = node->next;

			delete tmp;
		}

		_first = NULL;
		_cur = NULL;
	}

	List& operator=(List& rhv)
	{
		Clear();
		CopyFrom(rhv);
	}

	bool HasNext()
	{
		if (_cur != NULL
			&& _cur->next != NULL)
		{
			return true;
		}
		return false;
	}

	Student* GetNext()
	{
		if (_cur)
		{
			_cur = _cur->next;
		}

		if (_cur)
		{
			return &_cur->s;
		}
		return NULL;
	}
	Student* GetFirst()
	{
		_cur = _first;

		if (_cur == NULL)
		{
			return NULL;
		}
		return &_cur->s;
	}

	void PushBack(Student* s)
	{
		ListNode* tail = GetTail();
		ListNode* newNode = new ListNode;

		newNode->s = *s;
		newNode->next = NULL;

		if (tail != NULL)
		{
			tail->next = newNode;
		}
		else
		{
			_first = newNode;
		}
	}

	void RemoveCurrent()
	{
		if (_first == NULL && _cur == NULL)
		{
			return;
		}

		if (_first == _cur)
		{
			_first = _first->next;
			delete _cur;
			_cur = _first;
			return;
		}

		ListNode* left = FindLeftOf(_cur);

		if (left != NULL)
		{
			left->next = _cur->next;
			delete _cur;

			_cur = left->next;
		}
	}

	int GetCount()
	{
		int nCount = 0;
		ListNode* node = _first;
		while (node != NULL)
		{
			nCount = nCount + 1;
			node = node->next;
		}
		return nCount;
	}
private:
	void CopyFrom(List& list)
	{
		Student* s = NULL;
		for (s = list.GetFirst(); s != NULL; s = list.GetNext())
		{
			PushBack(s);
		}
	}

	ListNode* FindLeftOf(ListNode* node)
	{
		ListNode* tmp = _first;

		while (tmp && tmp->next != node)
		{
			tmp = tmp->next;
		}
		return tmp;
	}
private:
	ListNode* GetTail()
	{
		ListNode* node = _first;
		while (node != NULL
			&& node->next != NULL)
		{
			node = node->next;
		}
		return node;
	}
private:
	ListNode* _first;
	ListNode* _cur;
};
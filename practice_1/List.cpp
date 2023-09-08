#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

//����	cpp���װ,��ͷ,˫��,ѭ��
typedef int DataType;

//�ڵ�
class ListNode
{
	friend class List;
public:
	//���캯��	��ʼ��	
	ListNode()
		:_val(0)
		,_prev(nullptr)
		,_next(nullptr)
	{}

private:
	DataType _val;
	ListNode* _prev;
	ListNode* _next;
};

//����
class List
{
public:
	//���캯��	��ʼ��
	List()
		:_phead()
	{
		_phead = (ListNode*)malloc(sizeof(ListNode));
		_phead->_next = _phead;
		_phead->_prev = _phead;
	}

	//��������	�ͷ���Դ
	~List()
	{
		ListNode* cur = _phead->_next;
		while (cur != _phead)
		{
			ListNode* next = cur->_next;
			free(cur);
			cur = cur->_next;
		}
		free(_phead);
	}

	//pos֮ǰ����
	void PushInsert(DataType x,ListNode* pos)
	{
		assert(pos);

		ListNode* newnode = BuyNode(x);
		ListNode* prev = pos->_prev;

		prev->_next = newnode;
		newnode->_next = pos;
		pos->_prev = newnode;
		newnode->_prev = prev;
	}

	//pos֮�����
	void PushAfter(const DataType x, ListNode* pos)
	{
		//assert(pos);

		//ListNode* newnode = BuyNode(x);
		//ListNode* next = pos->_next;

		//pos->_next = newnode;
		//newnode->_next = next;
		//next->_prev = newnode;
		//newnode->_prev = pos;

		//����
		PushInsert(x, pos->_next);
	}

	//BUG�޸�:�߼��޸�,����ɾ��pos֮ǰ,��ɾ��pos��λ��
	void PopInsert(ListNode* pos)
	{
		assert(pos);
		//assert(pos->_prev != _phead);

		//ListNode* pprev = pos->_prev->_prev;
		//free(pos->_prev);
		//pprev->_next = pos;
		//pos->_prev = pprev;

		assert(pos != _phead);

		ListNode* prev = pos->_prev;
		ListNode* next = pos->_next;
		free(pos);
		prev->_next = next;
		next->_prev = prev;
	}

	void PopAfter(ListNode* pos)
	{
		//assert(pos);
		//assert(pos->_next != _phead);

		//ListNode* nnext = pos->_next->_next;
		//free(pos->_next);
		//pos->_next = nnext;
		//nnext->_prev = pos;

		//����
		PopInsert(pos->_next);
	}

	void PushBack(const DataType x)
	{
		PushAfter(x, _phead->_prev);
	}

	void PushFront(const DataType x)
	{
		PushAfter(x, _phead);
	}

	void PopBack()
	{
		PopInsert(_phead->_prev);
	}

	void PopFront()
	{
		PopAfter(_phead);
	}

	ListNode* Find(const DataType x)
	{
		ListNode* cur = _phead->_next;
		while (cur != _phead)
		{
			if (x == cur->_val)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return nullptr;
	}

	//ListNode �з����޶�,����ֱ���޸�����,��Ҫ�ӿں���
	void Change(const DataType x, ListNode* pos)
	{
		pos->_val = x;
	}

	void Print()
	{
		ListNode* cur = _phead->_next;
		while (cur != _phead)
		{
			cout << cur->_val << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
protected:
	ListNode* BuyNode(DataType x)
	{
		ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
		if (nullptr == newnode)
		{
			perror("BuyNode");
			exit(-1);
		}

		newnode->_val = x;
		return newnode;
	}

private:
	ListNode* _phead;
};


//int main()
//{
//	List ls;
//	ls.PushBack(1);
//	ls.PushBack(2);
//	ls.PushBack(3);
//	ls.PushBack(4);
//
//	ls.PushFront(1);
//	ls.PushFront(2);
//	ls.PushFront(3);
//
//	ls.Print();
//
//	while (ls.Find(1) != nullptr)
//	{
//		ls.Change(5, ls.Find(1));
//	}
//
//	ls.Print();
//
//	while (ls.Find(2) != nullptr)
//	{
//		ls.PopInsert(ls.Find(2));
//	}
//
//	ls.Print();
//
//	ls.PushInsert(7, ls.Find(3));
//	ls.PushAfter(8, ls.Find(4));
//
//	ls.Print();
//
//	return 0;
//}
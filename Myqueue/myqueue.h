#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
using namespace std;


//��: ջ
typedef int StData;
class Stack
{
public:
	//�ӿں���
	// 
	//���캯����ʼ��
	Stack(int capacity = 3)
	{
		std::cout << "Stack" << std::endl;
		StData* tmp = (StData*)malloc(sizeof(StData) * capacity);
		if (nullptr == tmp)
		{
			perror("malloc error");
			exit(-1);
		}
		_a = tmp;
		_capacity = capacity;
		_top = 0;
	}

	//�������캯��	==> ���
	Stack(const Stack& s)
	{
		StData* tmp = (StData*)realloc(this->_a, sizeof(StData) * s._capacity);//realloc������ԭ�ռ�
		if (nullptr == tmp)
		{
			perror("Stack(const Stack& s):malloc error");
			exit(-1);
		}
		else
		{
			_a = tmp;
			memcpy(_a, s._a, sizeof(StData) * s._top);
			_capacity = s._capacity;
			_top = s._top;
		}
	}



	//������������ջ
	~Stack()
	{
		std::cout << "~Stack:" << this << std::endl;
		assert(_a);
		free(_a);
		//������������ٶ�����,���Բ�������
		_a = nullptr;
		_capacity = _top = 0;
	}

	//��ջ
	void Push(const StData& x)	//�Ż�:StData x ==> const StData& x
	{
		//��Ȼ�Ҿ����ƺ�����assertҲ��,ʵ��������ͻᴴ��_a,����û��ʵ����
		assert(_a);
		//���ռ��Ƿ��㹻,����������
		Cheak();
		_a[_top] = x;
		_top++;
	}

	//��ջ
	void Pop()
	{
		assert(_a);
		assert(_top > 0);
		_top--;
	}
	//�п�
	bool IsEmpty()
	{
		assert(_a);
		return _top == 0;
	}

	//��С
	int Size()
	{
		assert(_a);
		return _top;
	}
	//��ȡTop
	StData Top()
	{
		assert(_a);
		assert(_top > 0);
		return _a[_top - 1];
	}

	//����Դ����(������Դmalloc),��Ҫ�Զ��帳ֵ���������
	Stack& operator=(const Stack& s)
	{
		StData* tmp = (StData*)realloc(_a, sizeof(StData) * s._capacity);//realloc������ԭ�ռ�
		if (nullptr == tmp)
		{
			perror("Stack& operator=(const Stack& s):malloc error");
			exit(-1);
		}
		else
		{
			//std::cout << "_a:" << _a << std::endl;
			//free(_a);//realloc������ԭ�ռ�
			_a = tmp;
			memcpy(_a, s._a, sizeof(StData) * s._top);
			_capacity = s._capacity;
			_top = s._top;
		}
	}

protected:
	//���ռ��Ƿ��㹻,����������
	void Cheak()
	{
		if (_capacity == _top)
		{
			_capacity *= 2;
			StData* tmp = (StData*)realloc(_a, sizeof(StData) * _capacity);//�����˳�sizeof(StData)
			if (nullptr == tmp)
			{
				perror("realloc error");
				exit(-1);
			}
			_a = tmp;
			tmp = nullptr;
		}
	}

private:
	//��̬��ֵʵ��
	StData* _a;
	int _capacity;
	int _top;
};



//��: ����(����ջʵ�ֶ���)
typedef int Qdata;
class MyQueue
{
public:
	//����,����,��������,�������ض���Ĭ�����ɵ�==>����Stack��


	//���
	void Push(Qdata x)
	{
		sPush.Push(x);
	}
	//����
	void Pop()
	{
		assert(!sPush.IsEmpty() || !sPop.IsEmpty());	//����ջ��ȫΪ��
		check();

		//spopջ��Ϊ��
		sPop.Pop();
	}

	//frontԪ��
	Qdata Front()
	{
		assert(!sPush.IsEmpty() || !sPop.IsEmpty());	//����ջ��ȫΪ��
		check();
		return sPop.Top();
	}
	//tailԪ��
	Qdata Tail()
	{
		assert(!sPush.IsEmpty() || !sPop.IsEmpty());	//����ջ��ȫΪ��
		assert(!sPush.IsEmpty());
		return sPush.Top();
	}

	//Ԫ�ظ���
	int Size()
	{
		return sPush.Size() + sPop.Size();
	}

	//�Ƿ�Ϊ��
	bool IsEmpty()
	{
		return sPush.IsEmpty() && sPop.IsEmpty();
	}

protected:
	//���sPopջ�Ƿ�Ϊ��,Ϊ��:��push���ݵ�pop
	void check()
	{
		//�ж�spopջ�Ƿ�Ϊ��
		if (sPop.IsEmpty())
		{
			//��,��spushջ���ݴ��ݵ�spop
			while (!sPush.IsEmpty())
			{
				sPop.Push(sPush.Top());
				sPush.Pop();
			}
		}
	}

private:
	Stack sPush;
	Stack sPop;
};
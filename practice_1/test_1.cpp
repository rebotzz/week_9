#include <iostream>
#include <assert.h>
using namespace std;

class Time
{
	friend class Date;	//��Ԫ��
public:
	Time(int hour)
		:_hour(hour)
	{
	}
private:
	int _hour;
};

//������
class Date
{

public:

	//���캯��,����ʵ����ʱ�Զ�����,��ʼ����Ա
	Date(int year = 1, int month = 1, int day = 1,int hour = 1)
		:_year(year)	//��ʼ���б�
		,_month(month)
		,_day(day)
		,_time(hour)
		,_cn(0)
	{
		//Time tmp(15);
		//_time = tmp;

		count++;
	}

	//void print(const Date* this) 
	void print() const
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
		cout << _time._hour << endl;

	}


	//static��Ա����
	static int count;

	//static��Ա����
	static int sum()
	{
		return num;	//���ܷ��ʳ�Ա,û��this ָ��
	}

private:
	//��������
	int _year;
	int _month;
	int _day;
	const int _cn;

	//�Զ���
	Time _time;	

	//�ܵ������޶�
	static int num;
};

//ֻ�����������ʼ��
int Date::count = 0;
int Date::num = 1;

class A
{
public:
	A(int& a,int b = 0)
		:_a(a)
		,_b(b)
	{
		_a = 10;
		cout << _a << endl;
	}
private:
	int& _a;
	int _b;
};


//int main()
//{
//	Date d1, d2, d3, d4;
//	cout << Date::count << endl;
//	//cout << Date::num;
//
//	Date d5;
//	d5.print();
//
//	int a = 3;
//	int b = 2;
//	A aa(a, 2);
//	cout << a << endl;
//
//	return 0;
//}
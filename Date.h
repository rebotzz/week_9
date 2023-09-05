#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

//������
class Date
{
public:

	//���캯��,����ʵ����ʱ�Զ�����,��ʼ����Ա
	Date(int year = 1, int month = 1, int day = 1)
	{
		this->_year = year;
		this->_month = month;
		this->_day = day;

		//������ںϷ���
		if (!CheckDate())
		{
			cout << "���������ڷǷ�" << endl;
		}
		assert(CheckDate());
	}

	//�������캯��		Ĭ��ǳ��������
	Date(const Date& d)
	{
		this->_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//��������		����Դ��Ҫ�ͷ�,Ĭ�Ϲ���
	//~Date()
	//{

	//}

	//��ӡ����
	void print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;

	}

	//��Ա�����������������
	//����==����
	bool operator == (const Date& d);

	//���� = ����
	Date& operator=(const Date& d);

	//++����
	Date& operator++();

	//����++
	Date operator++(int);

	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day);
	// ����-����
	Date operator-(int day);
	// ����-=����
	Date& operator-=(int day);

	// ����--
	Date operator--(int);
	// --����
	Date& operator--();

	// ����>����
	bool operator>(const Date& d);

	// ����>=����
	bool operator >= (const Date& d);

	// ����<����
	bool operator < (const Date& d);
	// ����<=����
	bool operator <= (const Date& d);
	// ����!=����
	bool operator != (const Date& d);
	// ����-���� ��������
	int operator-(const Date& d);


protected:
	//��ȡĳ��ĳ�µ�����
	//Ƶ������,inline
	int GetMonthDay(int year, int month)
	{
		//ÿ������,����,static
		static int mday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//�ж�ʱ��������2��:����%4,!%100,�� %400
		if (month == 2
			&& ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)))	//ע������
		{
			//std::cout << "�������:" << std::endl;
			return 29;
		}
		else
		{

			return mday[month];
		}
	}

	//������ںϷ���
	bool CheckDate()
	{
		if(_year > 0 
			&& (_month > 0 && _month < 13)
			&& (_day > 0 && _day <= GetMonthDay(_year, _month)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	//��������
	int _year;
	int _month;
	int _day;
};
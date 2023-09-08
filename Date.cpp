#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

//����==����		
bool Date::operator == (const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

//���� = ����		����������Ѵ���,d2.operator=(d1)
Date& Date::operator=(const Date& d)
{
	if (this != &d)	//��ȥ�Լ����Լ���ֵ
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;	//������������,��������
}

//++����
Date& Date::operator++()
{
	//1.0
	//_day++;
	//int day = GetMonthDay(_year, _month);
	//if (_day > day)
	//{
	//	_day -= day;
	//	_month++;
	//	if (_month > 12)
	//	{
	//		_month = 1;
	//		_year++;
	//	}
	//}

	//2.0
	* this += 1;	//����:+=����

	return *this;
}

//����++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;		//����:+=����
	return tmp;
}

// ����+=����
Date& Date::operator+=(int day)		//d.operator+=(day);
{
	//day < 0 �����
	// d + (-|day|) = d - |day|
	if (day < 0)
	{
		day = -day;
		*this -= day;
		return *this;
	}

	_day += day;
	int maxday = GetMonthDay(_year, _month);
	while (_day > maxday)	//��������,ʹ���ʽ�Ϸ�
	{
		_day -= maxday;
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
		maxday = GetMonthDay(_year, _month);
	}
	return *this;
}
// ����+����
Date Date::operator+(int day) const
{
	Date tmp(*this);
	tmp += day;		//���� +=
	return tmp;
}
// ����-����
Date Date::operator-(int day) const
{
	Date tmp(*this);
	tmp -= day;		//���� -=
	return tmp;
}
// ����-=����
Date& Date::operator-=(int day)
{
	//day < 0 ����С��0�����
	// d - (-|day|) = d + |day|
	if (day < 0)
	{
		day = -day;
		*this += day;
		return *this;
	}

	_day -= day;
	//����Ϊ����:�Ϸ� ; ����Ϊ����,��һ����
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}

		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

// ����--
Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;		//���� -=
	return tmp;
}
// --����
Date& Date::operator--()
{
	*this -= 1;		//���� -=
	return *this;
}

// ����>����
bool Date::operator>(const Date& d) const
{
	if (_year > d._year)	//���
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)		//�����,�´�
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)	//��,�����,������
	{
		return true;
	}
	else
	{
		return false;
	}
}

// ����>=����
bool Date::operator >= (const Date& d) const
{
	return (*this == d) || (*this > d);	//���� == >
}

// ����<����
bool Date::operator < (const Date& d)const
{
	return !(*this >= d);	//���� >=
}
// ����<=����
bool Date::operator <= (const Date& d)const
{
	return !(*this > d);	//���� >
}
// ����!=����
bool Date::operator != (const Date& d)const
{
	return !(*this == d);	//���� ==
}
//// ����-���� ��������		1.0
//int Date::operator-(const Date& d)
//{
//	Date d1 = *this;	//������
//	Date d2 = d;		//С����
//	int symbol = 1;		//������
//	int day = 0;		//�������
//	if (d1 < d2)
//	{
//		d1 = d;
//		d2 = *this;
//		symbol = -1;
//	}
//
//	//�����շֱ����	С����d2����,ֱ������d1
//	while (d1._year != d2._year)
//	{
//		//�ֽ�:3/1��,3/1֮ǰ���ܴ���2/29;
//		//3/1��֮�����:�����������������;֮ǰ,���ǽ���������	==> Ӱ���������
//		if (d2._month >= 3)
//		{
//			d2._year++;
//			if ((d2._year % 4 == 0 && d2._year % 100 != 0) || (d2._year % 400 == 0))
//			{
//				day += 366;
//			}
//			else
//			{
//				day += 365;
//			}
//		}
//		else
//		{
//			if ((d2._year % 4 == 0 && d2._year % 100 != 0) || (d2._year % 400 == 0))
//			{
//				day += 366;
//			}
//			else
//			{
//				day += 365;
//			}
//			d2._year++;
//		}
//	}
//
//	//�������������1/1�ŵ�����
//	int day1 = 0;
//	int day2 = 0;
//	Date tmp(d1._year, 1, 1);
//	while (tmp._month < d1._month)
//	{
//		day1 += GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//	}
//	day1 += d1._day - tmp._day;
//
//	tmp._month = tmp._day = 1;	//��ʼ��
//	while (tmp._month < d2._month)
//	{
//		day2 += GetMonthDay(tmp._year, tmp._month);
//		tmp._month++;
//	}
//	day2 += d2._day - tmp._day;
//
//	//�����������
//	int gap = day1 - day2;
//	day += gap;
//	return symbol * day;
//}

// ����-���� ��������	�����Ż�2.0
int Date::operator-(const Date& d)const
{
	Date max = *this;	//������
	Date min = d;		//С����
	int symbol = 1;		//������
	int day = 0;		//�������
	if (max < min)
	{
		max = d;
		min = *this;
		symbol = -1;
	}

	while (max != min)
	{
		min += 1;
		day += 1;
	}
	return symbol*day;
}



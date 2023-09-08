#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

//������
class Date
{
	//��Ԫ����,�ܷ���private,protected
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);


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

	//ȡ��ַ,Ҳ��Ĭ������,һ�㲻��д,���ǲ�������ȡ����ַ	( Date* const d)
	Date* operator&()
	{
		return this;
	}

	//constȡ��ַ,Ҳ��Ĭ������	(const Date* const d)
	const Date* operator&() const
	{
		return this;
	}

	//��ӡ����,const���κ��� ==> ����thisָ��,���������������,thisָ�����ݲ��ܱ��޸�,�ܽ�����ʱ����(������)
	//void print(const Date* this) 
	void print() const
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;

	}

	//��Ա�����������������
	//����==����
	bool operator == (const Date& d) const;

	//���� = ����
	Date& operator=(const Date& d);

	//++����
	Date& operator++();

	//����++
	Date operator++(int);

	// ����+=����
	Date& operator+=(int day);
	// ����+����
	Date operator+(int day) const;
	// ����-����
	Date operator-(int day) const; 
	// ����-=����
	Date& operator-=(int day);

	// ����--
	Date operator--(int);
	// --����
	Date& operator--();

	// ����>����
	bool operator>(const Date& d) const;

	// ����>=����
	bool operator >= (const Date& d) const;

	// ����<����
	bool operator < (const Date& d) const;
	// ����<=����
	bool operator <= (const Date& d) const;
	// ����!=����
	bool operator != (const Date& d)const;
	// ����-���� ��������
	int operator-(const Date& d)const;

	////operator<<(Date* const this, ostream& out)
	////d.operator<<(cout);
	// ����д�������,���Բ�����,ʹ��ȫ�ֺ��� + ��Ԫ����
	//ostream& operator<<(ostream& out)
	//{
	//	out << _year << "-" << _month << "-" << _day;
	//	return out;
	//}


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

	//������ںϷ���	�Ϸ�,ture
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



//inline:������������ܷ���,û�з��ű�,ֱ��չ��,���Գ���չ���ĵط�,���ܳ����ڱ�ĵط�,�����ӱ���
//��������� << ,cout����ostream���Ͷ���
//��������==>Ϊ��֧������ʹ��,cout<<d1<<d2;
//coutΪ<<���������,����Ա���������������thisָ��ռ����,ֻ��ȫ�ֺ���
inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "��" << d._month << "��" << d._day << "��" ;
	return out;
}

//��������� >> ,cin����istream���Ͷ���
inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	if (!d.CheckDate())
	{
		cout << "�������ڲ��Ϸ�." << endl;
	}
	return in;
}

//�˵�
enum MEUN
{
	EXIT,	//0
	ADD_SUB_DAY,	//1
	SUB_DATE		//2
};
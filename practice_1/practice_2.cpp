//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
////
////class A
////{
////public:
////	A(int a = 1)
////		:_a1(a)
////		, _a2(_a1)  //��������˳���ʼ��
////	{}
////
////	void Print() {
////		cout << _a1 << " " << _a2 << endl;
////	}
////private:
////	int _a2;
////	int _a1;
////};
////
//////int main() {
//////    A aa(1);
//////    aa.Print();
//////}
////
////
////
//class Date
//{
//
//public:
//	//Date(int year = 1,int test = 0)
//	//Date(int year, int test = 0)
//	//explicit Date(int year = 1)     //explicit ����,���ܷ�����ʽ����ת��
//	Date(int year = 1)
//		:_year(year)
//	{
//		cout << "Date(int year = 10 )" << endl;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		cout << "Date& operator=(const Date& d)" << endl;
//		_year = d._year;
//		return *this;
//	}
//
//	void print()
//	{
//		cout << _year << endl;
//	}
//private:
//	int _year;
//};
//
//int main()
//{
//	Date d(0);
//	//Date d1(123);
//
//	d.print();
//	d = 120;    //��ʽ����ת��(���캯��������,���߿���ֻ������һ������):���� + ��ֵ����
//	d.print();
//
//	return 0;
//}
//
//
//
////��Ԫ��
//
//class Time
//{
//	friend class Date;		//��Ԫ����Է���˽��,���ܵ������޶�
//public:
//	Time(int hour = 0, int minute = 0, int second = 0)
//		:_hour(hour*2 +5)
//		, _minute(minute)
//		, _second(second)
//	{}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//		//����û����ʾд,���Ǳ��붨����_t,��ʼ��
//	{}
//
//	void chTime(int hour = 0, int minute = 0, int second = 0)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//
//	void print()
//	{
//		cout << _year << "-" << _month << "-" << _day << "  ";
//		cout << _t._hour << ":" << _t._minute << ":" << _t._second << endl;
//	}
//
//	static void hello()
//	{
//		cout << "hello" << endl;
//	}
//	static int hehe;
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//
//int Date::hehe = 13;
//
//
////int main()
////{
////	Date d1(2023, 5, 7);
////	
////	d1.print();
////
////	d1.chTime(15, 56, 20);
////	d1.print();
////
////	Date::hello();
////	cout << Date::hehe << endl;
////
////	Date().print();		//��������
////
////	return 0;
////}
//
//
////�ڲ���
//class Tree
//{
//
//public:
//	class SubTree	//�յ������޶���Լ��	�ڲ������ⲿ���Сû�й�ϵ	�ڲ����ⲿ����Ԫ��
//	{
//	public:
//		void print(const Tree& t)
//		{
//			cout << "Tree: " << t._high << " " << t._circle << endl;
//		}
//	private:
//		int _num;
//	};
//
//private:
//	int _high = 20;
//	int _circle = 5;
//};
//
//
////int main()
////{
////	cout << sizeof(Tree) << "  " << sizeof(Tree::SubTree) << endl;
////
////	int i = 0;
////	cout << typeid(i).name() << endl;
////
////	Tree t;
////	Tree::SubTree st;
////	st.print(t);
////}
//
//
////��������
//#include <vector>
//
//class Sum
//{
//public:
//	Sum()
//	{
//		count += i;
//		++i;
//	}
//
//	static int count;
//private:
//	static int i;
//};
//int Sum::count = 0;
//int Sum::i = 1;
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		//Sum arr[n];		//�䳤����
//
//		//��ʹ�ñ䳤������������
//		for (int i = 1; i <= n; ++i)
//		{
//			Sum();		//��������,��������ֻ����һ��;
//		}
//		return Sum::count;
//	}
//};
//
////int main()
////{
////	cout << Solution().Sum_Solution(100);
////	return 0;
////}
//
//
//

#include <iostream>
#include <string>
using namespace std;

//class Time
//{
//public:
//	//Time(int hour = 0)
//	Time(int hour)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// Ҫ��ʼ��_t ���󣬱���ͨ����ʼ���б�
//	Date(int year, int hour)
//		:_t(hour)
//	{
//		// �������ڳ�ʼ��
//		_year = year;
//		//Time t(hour);
//		//_t = t;
//	}
//private:
//	int _year;
//	Time _t;
//};
//
//int main()
//{
//	Date d(2022, 1);
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour = 0)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	// Ҫ��ʼ��_t ���󣬿����ٺ������ڸ�ֵ�����ǻ��ǻ��߳�ʼ���б����Time��Ĭ�Ϲ���
//	//Date(int year, int hour)
//	//{
//	//	// �������ڳ�ʼ��
//	//	_year = year;
//	//	Time t(hour);
//	//	_t = t;
//	//}
//
//
//	Date(int year, int hour, int& x)
//		:_t(hour)
//		, _N(10)
//		, _ref(x)
//	{
//		// �������ڳ�ʼ��
//		_year = year;
//		_ref++;
//	}
//private:
//	int _year;
//	Time _t;
//	const int _N;
//	int& _ref;
//};
//
//// ���ۣ��Զ������ͳ�Ա���Ƽ��ó�ʼ���б��ʼ��
//// ��ʼ���б������Ϊ�ǳ�Ա��������ĵط�
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//	//const int N; // const�����ڶ���ĵط���ʼ����ֻ��һ�λ���
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////
//class Time
//{
//public:
//	Time(int hour = 0)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//
//
//// ���ۣ��Զ������ͳ�Ա���Ƽ��ó�ʼ���б��ʼ��
//// ��ʼ���б������Ϊ�ǳ�Ա��������ĵط�
//
//class Date
//{
//public:
//	//Date(int year, int hour, int& x)
//	//	: _N(10)
//	//	, _ref(x)
//	//{
//	//	// �������ڳ�ʼ��
//	//	_year = year;
//	//	_ref++;
//	//}
//	Date(int year, int hour, int& x)
//		:_year(year)
//		, _t(hour)
//		,_N(10)
//		, _ref(x)
//	{
//		_ref++;
//	}
//private:
//	// ����
//	int _year = 0;  // C++11  ȱʡֵ-- ��ʼ��ʱû����ʾ��ֵ�ͻ������ȱʡֵ
//	Time _t;
//	const int _N;
//	int& _ref;
//};
//
//int main()
//{
//	int y = 0;
//	Date d(2022, 1, y);
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////////
//class A
//{
//public:
//	/*A(int N)
//		:_a((int*)malloc(sizeof(int)*N))
//		, _N(N)
//	{
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}*/
//
//	// ��Щ��ʼ���������Ǳ����ں����������
//	A(int N)
//		:_N(N)
//	{
//		_a = (int*)malloc(sizeof(int)*N);
//		if (_a == NULL)
//		{
//			perror("malloc fail");
//		}
//		memset(_a, 0, sizeof(int)*N);
//	}
//private:
//	// ����
//	int* _a;
//	int _N;
//};
//
//int main()
//{
//	A aa(10);
//
//	return 0;
//}

// ��Ա������������������������ڳ�ʼ���б��еĳ�ʼ��˳�������ڳ�ʼ���б��е��Ⱥ�����޹�
//class A
//{
//public:
//	// ��ʼ��������˳���ʼ��
//	A(int a)
//	// ��Ա��������
//		:_a1(a)
//		, _a2(_a1)
//	{}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	// ��Ա��������
//	int _a2;
//	int _a1;
//};
//
////A.���1  1
////B.�������
////C.���벻ͨ��
////D.���1  ���ֵ
//
//int main() {
//	// D
//	// ������
//	A aa1(1);
//	aa1.Print();
//
//	A aa2(2);
//
//}

//////////////////////////////////////////////////////////////////////////
// explicit�ؼ��� + ��������
//class Date
//{
//public:
//	//explicit Date(int year)
//	Date(int year)
//		:_year(year)
//	{
//		cout << "	Date(int year)" << endl;
//	}
//
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d)" << endl;
//	}
//
//	~Date()
//	{
//		cout << "~Date()" << endl;
//	}
//private:
//	int _year;
//};
//
////string(const char* str)
////{}
//
//void func(const string& s)
//{}
//
//class Solution {
//public:
//	int Sum_Solution(int n) {
//		// ...
//		return 0;
//	}
//};
//
//int main()
//{
//	Date d1(2022);  // ֱ�ӵ��ù���
//	Date d2 = 2022; // ��ʽ����ת�������� + �������� + �������Ż� -��ֱ�ӵ��ù��� 
//	const Date& d3 = 2022;
//
//	int i = 10;
//	const double& d = i;
//
//	// �������� -- ��������ֻ����һ��
//	Date(2000);
//
//	Date d4(2000);
//
//	// �������� һЩʹ�ó���
//	Solution slt;
//	slt.Sum_Solution(10);
//	Solution().Sum_Solution(10);
//
//	string s1("hello");
//	string s2 = "hello";
//
//	string str("insert");
//	func(str);
//	func("insert");
//
//
//	return 0;
//}

////////////////////////////////////////////////////////////////////////////////

//class A
//{
//public:
//	A() 
//	{ ++_scount; }
//
//	A(const A& t) { ++_scount; }
//
//	// ��̬��Ա���� --  û��thisָ��
//	static int GetCount()
//	{
//		//_a = 1;
//
//		return _scount;
//	}
//
//private:
//	int _a;
//	// ��̬��Ա���������������࣬���������������������ڼ䣬���ھ�̬ȡ
//	static int _scount;  // ����
//};
//
//// �����涨���ʼ��
//int A::_scount = 0;
//
////int main()
////{
////	A a1;
////	A a2;
////	A a3(a2);
////
////	//cout << a1._scount << endl;
////	//cout << a2._scount << endl;
////	//cout << A::_scount << endl;
////
////	cout <<A::GetCount() << endl;
////
////	return 0;
////}
//
//// ���һ��ֻ����ջ�϶���������
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		StackOnly so;
//		return so;
//	}
//
//private:
//	StackOnly(int x = 0, int y = 0)
//		:_x(x)
//		, _y(0)
//	{}
//private:
//	int _x = 0;
//	int _y = 0;
//};
//
//int main()
//{
//	//StackOnly so1; // ջ
//	//static StackOnly so2; // ��̬��
//	StackOnly so3 = StackOnly::CreateObj();
//
//	return 0;
//}

///////////////////////////////////////////////////////////////////////////////////////////
// �ڲ���
//class A
//{
//private:
//	int _h;
//	static int k;
//public:
//	// B������A������
//	// 1����A���������ƣ������޶���
//	// 2��B������A����Ԫ
//	class B
//	{
//	public:
//		void foo(const A& a)
//		{
//			cout << k << endl;//OK
//			cout << a._h << endl;//OK -- ��Ԫ
//		}
//	private:
//		int _b;
//	};
//};
//int A::k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl; // 4
//	A a;
//	A::B b;
//
//	return 0;
//}
//

class W
{
public:
	W(int x = 0)
	{
		cout << "W()" << endl;
	}

	W(const W& w)
	{
		cout << "W(const W& w)" << endl;
	}

	W& operator=(const W& w)
	{
		cout << "W& operator=(const W& w)" << endl;
		return *this;
	}

	~W()
	{
		cout << "~W()" << endl;
	}
};

void f1(W w)
{

}

void f2(const W& w)
{

}

//int main()
//{
//	W w1;
//	f1(w1);
//	f2(w1);
//	cout << endl << endl;
//
//	f1(W()); // ��������+��������--���������Ż�--ֱ�ӹ���
//	// ���ۣ�����һ�����ʽ�����У���������һ�㶼���Ż� -- �϶�Ϊһ
//
//	W w2 = 1;
//
//	return 0;
//}

W f3()
{
	W ret;
	return ret;
}

// �����̽��C++����ģ�͡�
//int main()
//{
//	f3(); // 1�ι���  1�ο���
//	cout << endl << endl;
//
//	W w1 = f3(); // ������1�ι���  2�ο��� -- �Ż���1�ι���  1�ο���
//
//	cout << endl << endl;
//
//	W w2;
//	w2 = f3(); // ������1�ι���  1�ο��� 1�θ�ֵ
//
//	return 0;
//}

//W f(W u)
//{
//	//cout << "--------" << endl;
//	W v(u);
//	W w = v;
//	//cout << "--------" << endl;
//	return w;
//}
//
//int main()
//{
//	W x;
//	W y = f(f(x)); // 1�ι���  7�ο���  or  1�ι���  5�ο���
//
//	return 0;
//}

//int main()
//{
//	W x;
//	W y = f(x); // 1�ι���  4�ο���
//
//	return 0;
//}
#include <iostream>
using namespace std;

//编译器优化

class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}
	A(const A& aa)
		:_a(aa._a)
	{
		cout << "A(const A& aa)" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a = aa._a;
		}
		return *this;
	}
	~A()
	{
		cout << "~A()" << endl;
	}
private:
	int _a;
};
void f1(A aa)
{}
A f2()
{
	A aa;
	return aa;
}
//int main()
//{
//	// 传值传参
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// 传值返回
//	f2();
//	cout << endl;
//	// 隐式类型，连续构造+拷贝构造->优化为直接构造
//	f1(1);
//	// 一个表达式中，连续构造+拷贝构造->优化为一个构造
//	f1(A(2));
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+拷贝构造->优化一个拷贝构造
//	A aa2 = f2();
//	cout << endl;
//	// 一个表达式中，连续拷贝构造+赋值重载->无法优化
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}
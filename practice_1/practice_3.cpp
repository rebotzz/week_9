#include <iostream>
using namespace std;

//�������Ż�

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
//	// ��ֵ����
//	A aa1;
//	f1(aa1);
//	cout << endl;
//	// ��ֵ����
//	f2();
//	cout << endl;
//	// ��ʽ���ͣ���������+��������->�Ż�Ϊֱ�ӹ���
//	f1(1);
//	// һ�����ʽ�У���������+��������->�Ż�Ϊһ������
//	f1(A(2));
//	cout << endl;
//	// һ�����ʽ�У�������������+��������->�Ż�һ����������
//	A aa2 = f2();
//	cout << endl;
//	// һ�����ʽ�У�������������+��ֵ����->�޷��Ż�
//	aa1 = f2();
//	cout << endl;
//	return 0;
//}
#include <iostream>
using namespace std;

//int main()
//{
//	char s1[] = "const str";
//	const char* s2 = "const str";
//	cout << "s1:" << (void*)s1 << endl;
//	cout << "s2:" << (void*)s2 << endl;
//	cout << "const:" << (void*)"const str" << endl;
//	cout << "ps1:" << &s1 << endl;
//	cout << "ps2:" << &s2 << endl;
//	return 0;
//}


int main()
{
	class A
	{
	public:
		A(int a = 1, int b = 1)
			:_a(a)
			,_b(b)
		{
			cout << "A(int a = 1, int b = 1):" << this << endl;
		}

		~A()
		{
			cout << "~A():" << this << endl;
		}
	private:
		int _a;
		int _b;
	};

	A* pa = new A(1, 2);
	delete pa;

	//A* p2 = new A[3]{ (1,2),(2,3),(4,3) };	//����,������(,),���ű��ʽȡ���һ����ֵ
	A* p2 = new A[3]{ 1,2,3,};		//ʧ��,�����Զ������������ʼ��ֻ�ܳ�ʼ����һ��Ԫ��

	delete[] p2;

	return 0;
}
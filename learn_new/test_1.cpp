#include <iostream>

using namespace std;

class A
{
	int _a;
public:
	A()
	{
		cout << "A()" << endl;
	}
};

int main()
{
	A* pp1 = (A*)malloc(sizeof(A));		//û�г�ʼ��,���������,��ı�����δ֪


	return 0;
}
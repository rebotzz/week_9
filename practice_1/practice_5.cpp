#include <iostream>
using namespace std;

class AA
{
public:
	AA()		//���캯������private,��Ȼ���ܷ���
	{
	}
};

AA aa;

static AA bb;

//int main()
//{
//	AA aa;
//	return 0;
//}


int main()
{
	int a;
	int b;
	int c;
	printf("a:%p\n", &a);
	printf("b:%p\n", &b);
	printf("c:%p\n", &c);

	return 0;
}
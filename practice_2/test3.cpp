//#include <iostream>
//using namespace std;
//
////int main()
////{
////	char s1[] = "const str";
////	const char* s2 = "const str";
////	cout << "s1:" << (void*)s1 << endl;
////	cout << "s2:" << (void*)s2 << endl;
////	cout << "const:" << (void*)"const str" << endl;
////	cout << "ps1:" << &s1 << endl;
////	cout << "ps2:" << &s2 << endl;
////	return 0;
////}
//
//
//int main()
//{
//	class A
//	{
//	public:
//		A(int a = 1, int b = 1)
//			:_a(a)
//			,_b(b)
//		{
//			cout << "A(int a = 1, int b = 1):" << this << endl;
//		}
//
//		~A()		//��������������ʾ����
//		{
//			cout << "~A():" << this << endl;
//		}
//	private:
//		int _a;
//		int _b;
//	};
//
//	A* pa = new A(1, 2);
//	delete pa;
//
//	//A* p2 = new A[3]{ (1,2),(2,3),(4,3) };	//����,������(,),���ű��ʽȡ���һ����ֵ
//	A* p2 = new A[3]{ 1,2,3,};		//ʧ��,�����Զ������������ʼ��ֻ�ܳ�ʼ����һ��Ԫ��
//
//	delete[] p2;
//	
//	//��λnew
//	A* p3 = (A*)malloc(sizeof(A));
//	new(p3)A(10);
//	p3->~A();			//�ֶ���������
//	free(p3);
//	//delete(p3);		//�����Ӧ����free,�Ͼ��ռ���malloc��;����û�е�������
//
//	A* p4 = (A*)malloc(sizeof(A) * 4);
//	const int num = 3;
//	new(p4)A[num]{ 4,5,6 };			//��������ñ���,�Ͼ�malloc�����ñ������ٿռ�,����ֱ�ӵ����鶨��
//	for (int i = 0; i < num; i++)
//	{
//		(p4 + i)->~A();
//	}
//	//delete[] p4;			//������delete[] ������ѭ����,����λnewû�м�¼��Ҫ���ö��ٴ�����
//	//delete p4;			//��delete,Ȼ��delete����free,free������¼�˿��ٶ��ռ�,�����ͷŶ�Ӧ��С;
//	free(p4);				//����deleteֻ������һ������.	==>�ܽ�:�����Ӧ����free,�Ͼ��ռ���malloc��
//
//
//	//operator new(); operator delete();�Ǻ���,��malloc����,����ʼ��,����������
//	A* p5 = (A*)operator new(sizeof(A));	
//	//new(p5)A;
//	//p5->~A();
//	operator delete(p5);
//
//
//	return 0;
//}
#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

void test1()
{
	Date d1(2023, 8, 31);
	Date d2;
	d2 = d1;	//d2.operator=(d1);	thisָ������
	(++d2).print();
	//(d2++).print();
	(--d2).print();
	//(d2--).print();

	//cout << (d1 >= d2) << endl;


	(d2 + 50).print();
	(d2 + 500).print();
	(d2 + 5000).print();
	(d2 + 50000).print();

	cout << endl;
	d2 -= 50;
	d2.print();
	d2 -= 500;
	d2.print();
	d2 -= 5000;
	d2.print();
	d2 -= 50000;
	d2.print();
	cout << endl;

	d2 = d1;
	(d2 - 50).print();
	(d2 - 500).print();
	(d2 - 5000).print();
	(d2 - 50000).print();
	cout << endl;

	d2 += 5087640;
	d2.print();
	cout << (d1 - d2) << endl;

	cout << endl;
	Date d3(1999, 3, 7);
	cout << (d1 - d3) << endl;
	d3.operator+=(1);
	d3.print();
}

void test2()
{
	Date d1(2023, 2, 28);

	(d1 + -3).print();
	(d1 - -3).print();

}


//void test3()
//{
//	typedef char* pstring;
//
//	const pstring p1;    // ����ɹ�����ʧ�ܣ�	err,���������ʼ��
//	const pstring* p2;
//}

void test4()
{

	Date d1(2023, 5, 7);
	cout << d1;
	cin >> d1;
	cout << d1;
	Date* pd1 = &d1;
	int* tmp = (int*)&d1;
	*tmp = 100;	//privateֻ�ڱ���׶����Ʒ���,���ڴ���û�����Ʒ���
	*pd1 = 123;	//��ʽ����ת��,����(123����һ����ʱDate����) + ��ֵ���� (��ʱ����ֵd1)
	cout << d1;

	Date d2 = d1 + 1231;
	cout << d1 << d2;
	cin >> d1 >> d2;
	cout << d1 << d2;

}

//�˵�
void meun()
{
	printf("********************       ���ڼ�����       ******************\n");
	printf("**************** 1.����+/-����   2.���� - ����  **************\n");
	printf("**************** 0.�˳�                         **************\n");
	printf("**************************************************************\n");

}

void test5()
{
	int input = 1;
	Date d;
	Date d1;
	int day;
	//�ܼ�
	char week[][7] = { "��һ","�ܶ�","����" ,"����" ,"����" ,"����","����" };
	int num = 0;
	Date d0(1, 1, 1);

	//ע��,�������û������0�����˳�,���̻����ڴ���, ���ڶ���״̬,ռ���ڴ�  �رմ����ܹص�������??ǰ̨����
	do
	{
		//�˵�
		meun();
		cout << "������ѡ��:>";
		cin >> input;
		switch (input)
		{
		case EXIT:
			cout << "�˳�����.";
			break;
		case ADD_SUB_DAY:
			cout << "���������ں�Ҫ�Ӽ�������(+/-),��(-)���븺��:>";
			cin >> d >> day;
			d += day;
			num = (d - d0) % 7;
			//cout << "tmp:"<<tmp<<"   w:" << wday << endl;
			cout << "���:" << d << " " << week[num] << endl;
			break;
		case SUB_DATE:
			cout << "������Ҫ���������:>";
			cin >> d >> d1;
			cout << "���:" << (d - d1) << "��" << endl;
		}

	} while (input);
}

int main()
{
	test5();

	//Date d(2023, 9, 7);
	//Date d0(1, 1, 1);
	//d.operator<<(cout) << endl;
	//cout << (d - d0) << endl;
	//d += 1;
	//cout << (d - d0) << endl;


	return 0;
}
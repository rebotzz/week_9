#include <iostream>
#include <string>
using namespace std;

int main()
{
	//���ո��滻Ϊ%20



	string s1 = "hello world i love you";
	cout << s1 << endl;
	//�Ż�1.0	һ���Կ��ٺÿռ�
	//int num = 0;
	//for (auto ch : s1)
	//{
	//	if (ch == ' ')
	//	{
	//		num++;
	//	}
	//}
	//s1.reserve(s1.size() + 2 * num);

	//size_t pos = s1.find(' ');
	//while (pos != s1.npos)
	//{
	//	s1.replace(pos, 1, "%20");
	//	pos = s1.find(' ', pos + 3);
	//}
	//cout << s1 << endl;

	//�Ż�2.0	ʱ�任�ռ�
	string tmp;
	int num = 0;
	for (auto ch : s1)
	{
		if (ch == ' ')
		{
			num++;
		}
	}
	tmp.reserve(s1.size() + 2 * num);

	for (auto ch : s1)
	{
		if (ch == ' ')
		{
			tmp += "%20";
		}
		else
		{
			tmp += ch;
		}
	}
	s1 = tmp;
	cout << s1 << endl;

	return 0;
}
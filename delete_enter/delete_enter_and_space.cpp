#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAX 100000

int main()
{
	//test1();

	FILE* pf = fopen("1.txt", "r");
	char* str = (char*)malloc(sizeof(char) * MAX);
	char* begin = str;

	//��ȡ�ļ����ڴ�
	char ch;	//utf-8 һ�����������ַ�,������; ����BUG,�����ĵ������ʽ��ΪANSI
	int i = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		if (ch != ' ' && ch != '\n')
		{
			str[i++] = ch;
			//i += 2;
		}
	}
	str[i] = 0;


	//���ڴ��е�����д���ļ�
	FILE* fout = fopen("out.txt", "w");

	cout << str << endl;

	fprintf(fout, "%s\n", str);
	fflush(fout);

	fclose(fout);
	fout = NULL;


	free(begin);
	begin = NULL;
	fclose(pf);
	pf = NULL;
	return 0;
}
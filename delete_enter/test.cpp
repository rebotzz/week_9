//#define _CRT_SECURE_NO_WARNINGS
////#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <iostream>
//using namespace std;
//
//#define MAX 10000
//
//
//void test()
//{
//	//const char* str = "��";
//	//printf("%s", str);
//
//	char s[1000], ch;
//	FILE* fp;
//	int i = 0;
//	if ((fp = fopen("123.txt", "r")) == NULL) {
//		printf("Open the file failure...\n");
//		exit(0);
//	}
//	while ((ch = fgetc(fp)) != EOF)
//		if (ch < 0)
//			s[i++] = ch;
//	fclose(fp);
//	s[i] = '\0';
//	printf("%s\n", s);//���������
//
//}
//
//void test1()
//{
//	char str[] = "���,������aa\n";
//	cout << str << endl;
//
//
//	char s[1000], ch;
//	FILE* fp = fopen("tmp.txt", "w");
//	fprintf(fp, "%s\n", str);
//
//	fclose(fp);
//}
//
//int main()
//{
//	//test1();
//
//	FILE* pf = fopen("1.txt", "r");
//	char* str = (char*)malloc(sizeof(char) * MAX);
//	char* begin = str;
//
//	//��ȡ�ļ����ڴ�
//	char ch;	//utf-8 һ�����������ַ�,������
//	int i = 0;
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		if (ch != ' ' && ch != '\n')
//		{
//			str[i++] = ch;
//			//i += 2;
//		}
//	}
//	str[i] = 0;
//
//	//printf("%s\n", begin);
//
//	//���ڴ��е�����д���ļ�
//	FILE* fout = fopen("out.txt", "w");
//	//for (int j = 0; j <= i; j++)
//	//{
//	//	fputc(str[j], pf);
//	//}
//	cout << str << endl;
//
//	fprintf(fout, "%s\n", str);
//	fflush(fout);
//
//	fclose(fout);
//	fout = NULL;
//
//
//	free(begin);
//	begin = NULL;
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
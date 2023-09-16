#include <stdio.h>
#include <stdlib.h>


//ֻ��������,��Χ����
//ʱ�临�Ӷ�O(N + Range); �ռ临�Ӷ�O(Range);
void CountSort(int* a, int n)
{
	//����,�ҳ�min,max
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	//��Χ
	int range = max - min + 1;
	int* num = (int*)calloc(range, sizeof(int));	//��ʼ��0
	//����
	for (int i = 0; i < n; i++)
	{
		num[a[i] - min]++;		//��¼min+i�����ֳ��ִ���
	}

	//����
	int k = 0;
	for (int i = 0; i < range; i++)
	{
		while (num[i]-- > 0)	//num[i]��¼��min+i�����ֳ��ִ���
		{
			a[k++] = min + i;	
		}
	}
}


int main()
{
	int arr[] = { 5,7,6,1,2,5,9,4,1,3,1,13,5,21,5,3,4,8,3,1 };
	//int arr[] = { 4,3,2,1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	CountSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
/*
	指针实现quickSort时候会因为指针链接指针,导致全局数据的改变.
	剪不断理还乱的关系还不如设定全局变量.
	虽然工程中还是得想办法独立包装出来
*/ 

#include <iostream>
#include <cstdio>
using namespace std;
void bucketSort(int *pArray,int length)
{
	int tmp;
	for (int i = 0; i < length; ++i) pArray[i] = 0;
	for (int i = 0; i < length; ++i)
	{
		scanf("%d", &tmp);
		pArray[tmp]++;
	}
	return ;
}
void bubbleSort(int *pArray, int length)
{
	for (int i = 0; i < length-1; ++i)
	{
		for (int j = 0; j < length-i; ++j)
		{
			if (pArray[j] > pArray[j+1])
			{
				int cnt = pArray[j+1];
				pArray[j+1] = pArray[j];
				pArray[j] = cnt;
			}
		}
	}
}
void fail_quickSort(int *left, int *right)
{
	if (*left > *right) return;
	int temp = *left;
	int *i = left;
	int *j = right;
	while(i != j)
	{
		while(*j >= temp && i<j) j--;
		while(*i <= temp && i<j) i++;
		if (i < j)
		{
			int cnt = *i;
			*i = *j;
			*j = cnt;
		}
	}
	*left = *i;
	*i = temp;
	fail_quickSort(left, i-1);
	fail_quickSort(i+1, right);
	return ;
}

void quickSort(int *a,int left, int right)
{
	if(left > right) return;
	int temp = a[left];
	int i = left;
	int j = right;
	while(i!=j)
	{
		while(a[j] >= temp && i<j) j--;
		while(a[i] <= temp && i<j) i++;
		if (i<j)
		{
			int cnt = a[i];
			a[i] = a[j];
			a[j] = cnt;
		}
	}
	a[left] = a[i];
	a[i] = temp;

	quickSort(a,left,i-1);
	quickSort(a,i+1,right);
	return;
}
int main()
{
	int a[10] = {6,1,2,7,9,3,4,5,10,8};
	quickSort(a,0,9);
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;

void InsertSort(int *pArray, int len)
{
	int iTemp;
	int iPos;
	for (int i = 1; i < len; ++i)
	{
		iTemp = pArray[i];
		iPos = i-1;
		while(iPos >= 0 && iTemp < pArray[iPos])
		{
			pArray[iPos + 1] = pArray[iPos];
			iPos--;
		}
		pArray[iPos+1] = iTemp;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[1004];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	InsertSort(a,n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", a[i]);
	}
	return 0;
}
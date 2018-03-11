#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int main()
{
	int n,t;
	int a[1003];
	// int m;
	int sum;
	while(~scanf("%d%d", &n,&t))
	{

		sum=0;
		memset(a,0,sizeof(a));
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		a[n] = 12;
		int i,j;
		for (i = 0; i < n;)
		{
			int smlSum = a[i];
			for (j = i+1;  abs(smlSum + a[j] - t) < abs(smlSum - t) ; ++j)
			{
				smlSum += a[j];
			}
			sum += (smlSum-t)*(smlSum-t);
			i = j;
		}
		printf("%d\n", sum);
	}
	return 0;
}
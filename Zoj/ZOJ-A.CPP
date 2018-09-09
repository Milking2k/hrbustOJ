#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		int a[100002];
		memset(a,0,sizeof(a));
		long long int sum=0;
		scanf("%d%d",&n,&m);
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		if (n%2 == 1)
		{
			n-=1;
		}
		for (int i = 0; i < m; ++i)
		{
			sum +=	a[i]*a[2*m-1-i];
		}
		printf("%lld\n", sum);
	}
	return 0;
}
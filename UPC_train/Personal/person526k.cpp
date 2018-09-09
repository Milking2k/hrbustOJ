#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

typedef long long LL;
int n;
int m;
char emt[107][107];
int main()
{
	LL a,b,c;
	while(~scanf("%d%d",&n,&m))
	{
		for (int i = 1; i <= n; ++i)
		{
			scanf("%s",emt[i]);
		}
		for (int i = 1; i <= 2*n; ++i)
		{
			// for (int j = 1; j <= m; ++j)
			printf("%s\n", emt[(i+1)/2]);
		}
	}
	return 0;
}
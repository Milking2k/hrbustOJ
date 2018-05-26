#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

typedef long long LL;
int n;
LL m;
LL emt[100007];
int main()
{
	while(~scanf("%d%lld",&n,&m))
	{
		// printf("te\n");
		LL ans=0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld",&emt[i]);
			// printf("test1\n");
			if(i>1)
			{
				LL cnt=max(emt[i]+emt[i-1]-m,0ll);
				ans+=cnt;
				if(cnt >= emt[i]) emt[i]=0;
				else emt[i] -= cnt;
			// printf("test2\n");
			}
			// printf("test3\n");
		}
		printf("%lld\n", ans);
	}
	return 0;
}
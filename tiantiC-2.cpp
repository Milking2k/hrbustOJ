#include <bits/stdc++.h>
using namespace std;
#define rd(x) scanf("%d",&x)
#define r1d(x) scanf("%1d",&x)
#define rdd(x) scanf("%d%d",&x,&y)
#define rddd(x) scanf("%d%d%d",&x,&y,&z)
#define ll long long int

int n;
int emt[105];
int cnt;
int ans;
int main()
{
	// freopen("in.txt","r",stdin);
	while(~rd(n))
	{
		cnt=0,ans=0;
		fill(emt,emt+105,0);
		for (int i = 0; i < n; ++i)
		{
			rd(emt[i]);
			cnt += emt[i];
		}
		cnt /= n;
		for (int i = 0; i < n; ++i)
		{
			emt[i] -= cnt;
		}
		for (int i = 0; i < n; ++i)
		{
			if(emt[i]==0) continue;
			emt[i+1] += emt[i];
			ans++;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}
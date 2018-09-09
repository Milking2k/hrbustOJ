#include <bits/stdc++.h>
using namespace std;
int n,sum[10],ans,now;

int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		int x;
		scanf("%d",&x);
		sum[x]++;
	}
	while(n)
	{
		ans++;
		now=5;
		for (int i = 5; i >= 1; --i)
		{
			while(sum[i]&&now>=i)
				sum[i]--,now-=i,n--;
		}
	}
	printf("%d\n", ans);

	return 0;
}
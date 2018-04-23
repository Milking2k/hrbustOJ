// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;
int a[1000005];
int dp[1000005];
int pre[1000005];

int main(int argc, char const *argv[])
{
	// freopen("in.txt","r",stdin);

	while(~scanf("%d%d",&m,&n))
	{
		int ans;
		for (int i = 1; i <= n; ++i) scanf("%d",&a[i]);
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		for (int i = 1; i <= m; ++i)
		{
			ans = -0x3f3f3f3f;
			for (int j = i; j <= n; ++j)
			{
				dp[j] = max(dp[j-1]+a[j],pre[j-1]+a[j]);
				pre[j-1] = ans;
				ans = max(ans,dp[j]);
			}
		}
		printf("%d\n", ans);
	}


	return 0;
}
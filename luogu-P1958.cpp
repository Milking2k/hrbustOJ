#include <bits/stdc++.h>
using namespace std;


int dp[17][17];
int vis[17][17];

int main(int argc, char const *argv[])
{
	int a,b,n;
	scanf("%d%d%d",&a,&b,&n);	
	memset(dp,0,sizeof(dp));
	memset(vis,0,sizeof(vis));
	for (int i = 0; i < n; ++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vis[x][y] = 1;	
	}
	dp[1][1] = 1;
	for (int i = 1; i <= a; ++i)
	{
		for (int j = 1; j <= b; ++j)
		{
			if(vis[i-1][j]!=1) dp[i][j] += dp[i-1][j];
			if(vis[i][j-1]!=1) dp[i][j] += dp[i][j-1];
		}
	}
	printf("%d\n", dp[a][b]);
	return 0;
}
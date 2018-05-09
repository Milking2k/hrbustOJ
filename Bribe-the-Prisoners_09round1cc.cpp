#include <bits/stdc++.h>
using namespace std;
#define MAX_Q 100
#define MAX_P 1e4
// #define INT_MAX 0x3f3f3f3f

int P,Q,A[MAX_Q+7];
int dp[MAX_Q+7][MAX_Q+7];
void solve()
{
	A[0]=0;
	A[Q+1] = P+1;
	//init
	for (int i = 0; i <= Q; ++i)
	{
		dp[i][i+1] = 0;
	}
	for (int w = 2; w <= Q+1; ++w)
	{
		for (int i = 0; i + w <= Q+1; ++i)
		{
			int j = i+w,t=INT_MAX;
			for (int k = i+1; k < j; ++k)
			{
				t = min(t,dp[i][k]+dp[k][j]);
			}
			dp[i][j] = t+A[j]-A[i]-2;
		}
	}
	printf("%d\n", dp[0][Q+1]);
}
int main(int argc, char const *argv[])
{
	while(scanf("%d%d", &P, &Q))
	{
		for (int i = 1; i <= Q; ++i)
		{
			scanf("%d",&A[i]);
		}
		solve();
	}
	return 0;
}
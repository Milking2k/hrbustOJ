#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int ll;
int n;
int maxNum[55];
ll dp[55];

int main(int argc, char const *argv[])
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> maxNum[i];
	}
	sort(maxNum+1,maxNum+1+n);
	dp[1] = maxNum[1];
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = (maxNum[i]-i+1)*dp[i-1] % MOD;
	}
	printf("%lld\n", dp[n]);

	return 0;
}
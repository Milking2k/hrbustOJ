// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long int 
// #define mod 1000000007
int yh3[2005][4010];
int sum[2005][4010];
ll quick_mod(ll a,ll b,ll mod)
{
	ll ans = 1;
	ll base = a % mod;
	while(b)
	{
		if(b&1) ans = ans*base%mod;
		base = base*base%mod;
		b >>= 1;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int t,k;
	cin >> t >> k;
	memset(yh3,0,sizeof(yh3));
	memset(sum,0,sizeof(sum));
	for (int i = 0; i < 2000; ++i)
	{
		yh3[i][0] = 1;
	}
	yh3[1][1]=1;
	for (int i = 2; i < 2000; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			yh3[i][j] = (yh3[i-1][j] + yh3[i-1][j-1])%k;
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			if (yh3[i][j] == 0)
			{
				sum[i][j]++;
			}
		}
		sum[i][i+1]=sum[i][i];
	}
	while(t--)
	{
		int n,m,p;
		cin >> n >> m;
		printf("%d\n", sum[n][min(n,m)]);
	}
	return 0;
}
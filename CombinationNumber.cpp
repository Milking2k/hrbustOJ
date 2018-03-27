// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define ll long long int 
// #define mod 1000000007
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

ll C(ll n, ll m, ll mod)
{
	ll up = 1;
	ll down = 1;
	if(m<=0) return 0;
	else if(n<m) return 0;
	else if(n==m) return 1;
	else if(m>n-m) m = n-m;
	for (int i = 1; i <= m; ++i)
	{
		up = up*(n+i-m)%mod;
		down = down*i%mod;
	}
	return up*quick_mod(down,mod-2,mod)%mod ;
}

ll lucas(ll n,ll m,ll mod)
{
	if(m==0) return 1;
	return C(n%mod,m%mod,mod)*lucas(n/mod,m/mod,mod)%mod;
}

int main(int argc, char const *argv[])
{
	int t,k;
	cin >> t >> k;
	while(t--)
	{
		int n,m,p;
		cin >> n >> m;
		int count=0;
		// printf("%lld\n", lucas(n,m,1000000007));
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= min(i,m); ++j)
			{
				if (lucas(i,j,1000000007) % k == 0)
				{
					count++;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
// #define mod 1000000007
ll quick_mod(ll a,ll b,ll mod)
{
	ll ans=1;
	ll base = a%mod;
	while(b)
	{
		if(b&1) ans = ans*base%mod;
		base = base*base%mod;
		b>>=1;
	}
	return ans;
}
ll C(ll n,ll m,ll mod)
{
	ll up = 1;
	ll down = 1;
	if(m<0)return 0;
	else if(n<m)return 0;
	else if(n==m)return 1;
	else if(m<n-m)m=n-m;
	for (int i = 1; i < m; ++i)
	{
		up = up*(n+i-m)%mod;
		down = down*i%mod;
	}
	return up*C(down,mod-2,mod)%mod;
}

ll lucas(ll n,ll m,ll mod)
{
	if(m==0)return 1;
	return C(n,m,mod)*lucas(n/mod,m/mod,mod)%mod;
}

int main(int argc, char const *argv[])
{
	int n,m;
	while(cin >> n >> m)	
	{
		printf("%lld\n", lucas(n,m,1000000007));
	}

	return 0;
}
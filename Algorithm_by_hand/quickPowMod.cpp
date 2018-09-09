#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define	 mod 1000000007
ll quick_mod(ll a,ll b)
{
	ll ans = 1;
	ll base = a%mod;
	while(b)
	{
		if(b&1) ans = ans*base % mod;
		base = base*base % mod;
		b >>= 1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	ll a,b;
	cin >> a >> b;
	printf("%lld\n", quick_mod(a,b));
	return 0;
}
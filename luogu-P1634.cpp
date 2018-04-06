#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	ll n;
	ll x;
	ll ans=1;
	scanf("%lld%lld",&x,&n);
	for (int i = 0; i < n; ++i)
	{
		ans = ans + ans*x;
	}
	printf("%lld\n", ans);
	return 0;
}
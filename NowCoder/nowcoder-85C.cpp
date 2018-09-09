#include <bits/stdc++.h>
using namespace std;

long long foo(long long e, long long x, long long m)
{
	if (x==0)
	{
		return 0;
	}
	long long ret = 1;
	while(x)
	{
		if (x & 1)
		{
			ret = ret * e % m;
		}
		e = e * e % m;
		x >>= 1;
	}
	return ret;
}
int main(int argc, char const *argv[])
{
	long long a,b,c,d,t;
	while(scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &d, &t) == 5)
	{
		a %= t;
		b %= t;
		printf("%lld\n", foo(a*b%t, c*d, t));
	}
	return 0;
}
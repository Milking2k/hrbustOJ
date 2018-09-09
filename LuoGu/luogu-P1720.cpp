// fn=((1+sqrt(5))^n - (1-sqrt(5))^n)/sqtr(5);
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	ll a=1,b=1,ans=0;
	for (int i = 3; i <= n; ++i)
	{
		ans = a+b;
		a = b;
		b = ans;
	}
	printf("%lld.00\n", ans);
	return 0;
}
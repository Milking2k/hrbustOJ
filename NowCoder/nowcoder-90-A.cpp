#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		long long int ans;
		cin >>n;
		ans = pow(2,n-1);
		printf("%lld\n", ans);
	}
	return 0;
}
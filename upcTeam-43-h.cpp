#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,l;
	cin >> n >> l;
	int a[100005];
	int sum=0;
	a[0]=0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum = max(a[i]+a[i-1],sum);
	}
	if(sum >= l)
		printf("Possible\n");
	else
		printf("Impossible\n");

	return 0;
}
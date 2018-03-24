#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[100005];
		int sum=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += a[i];
		}
		sort(a,a+n);
		// printf("%d %d \n", a[0],a[n-1]);
		printf("%d %d\n", sum-n*a[0], sum-n*a[0]+a[0]);
		
	}
	return 0;
}
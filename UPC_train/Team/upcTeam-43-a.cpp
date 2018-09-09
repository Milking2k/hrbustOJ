#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a[205];
	cin >> n;
	for (int i = 0; i < 2*n; ++i)
	{
		cin >> a[i];
	}
	sort(a,a+2*n);
	int sum=0;
	for (int i = 0; i < 2*n; i=i+2)
	{
		sum += a[i];
	}
	printf("%d\n", sum);
	return 0;
}
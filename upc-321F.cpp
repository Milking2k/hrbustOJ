#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101];
int fmin()
{
	int minnum=0x3f3f3f3f;
	int pos=0;
	for (int i = 0; i < m; ++i)
	{
		if (a[i] <= minnum)
		{
			minnum = a[i];
			pos = i;
		}
	}
	return pos;
}
int fmax()
{
	int maxnum = 0;
	for (int i = 0; i < m; ++i)
	{
		if (a[i] >= maxnum)
		{
			maxnum = a[i];

		}
	}
	return maxnum;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m;
	if (n <= m)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		printf("%d\n", fmax());
		return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i];
		// printf("%d  ", a[i]);
	}
	for (int i = 0; i < n-m; ++i)
	{
		int cnt;
		cin >> cnt;
		// printf("min:%d\n", fmin() );
		a[fmin()] += cnt;
		// for (int j = 0; j < m; ++j)
		// {
		// 	printf("%d ", a[j]);
		// }
	}
	printf("%d\n", fmax());
	return 0;
}
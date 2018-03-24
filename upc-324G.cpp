#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[20001];
	int n=1;
	int j=0;
	for (int i = 1; i < 10005; ++i)
	{
		a[i] = a[i-1] + n;
		j++;
		if (j == n)
		{
			j = 0;
			n++;
		}
	}

	// for (int i = 1; i <= 20; ++i)
	// {
	// 	printf("a[%d]=%d  ", i,a[i]);
	// }

	int k;
	cin >> k;
	printf("%d\n", a[k]);
	return 0;
}
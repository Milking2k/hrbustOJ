//unfinished
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;
// 362880
int a[2004];
int tmp;
int pos = 1;
int maxN;
int len;
void check(int *parray, int pos)
{
	if (a[pos] == 0)
		return;
	for (a[pos] = 1; a[pos] <= maxN; (a[pos]) = a[pos] + 1)
	{
		if ((a[pos - 1] % a[pos] == 0) && (a[pos + 1] == 0 || (a[pos] % a[pos + 1] == 0)))
		{
			check(a, pos + 1);
			tmp++;
			printf("%d", tmp);
		}
	}
	a[pos] = 1;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		tmp = 0;
		a[0] = 362880;
		cin >> maxN >> len;
		printf("max=%d len=%d\n", maxN, len);
		for (int i = 1; i <= len; ++i)
		{
			a[i] = 1;
		}
		for (int i = 0; i < len + 2; ++i)
		{
			printf("_%d_\n", a[i]);
		}
		check(a, 1);
		printf("\nans = %d\n", tmp);
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int p[20005];
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int cnt;
	for (int i = 1; i <= n; ++i)
	{
		cin >> cnt;
		p[cnt] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d", n * i);
		if(i==n)printf("\n");
		else printf(" ");
	}
	for (int i = 1; i <= n; ++i)
	{
		printf("%d", (n - i) * n + p[i]);
		if(i==n) printf("\n");
		else printf(" ");
	}
	return 0;
}

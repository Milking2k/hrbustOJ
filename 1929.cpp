#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int m=0,n=1;
	int ans[21];
	ans[0] = 0;
	for (int i = 1; i <= 20; ++i)
	{
		int t = n;
		n = m + n;
		m = m + 2*t;
		ans[i] = m + n;
	}
	while(~scanf("%d", &n))
	{
		printf("%d\n", ans[n]);
	}
	return 0;
}
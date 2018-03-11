#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5+2;
int pre[maxn];
int vis[maxn];

int check(int x)
{
	int sum=0;
	while(x)
	{
		if (x%10 == 1)
		{
			sum++;
		}
		x /= 10;
	}
	return sum;
}
int main()
{
	int n;
	memset(vis,0,sizeof(vis));
	for (int i = 1; i <= maxn; ++i)
	{
		vis[i] = check(i);
	}
	pre[0] = 0;
	for (int i = 1; i <= maxn; ++i)
	{
		pre[i] = pre[i-1] + vis[i];
	}
	while(~scanf("%d", &n))
	{
		printf("%d\n", pre[n]);
	}

	return 0;
}
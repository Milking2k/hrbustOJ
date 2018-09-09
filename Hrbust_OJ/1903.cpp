#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	int a[10005];
	int vis[10005];
	scanf("%d", &t);
	while(t--)
	{
		int n;
		int m;
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		int j=0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &m);
			if (!vis[m+5000])
			{
				a[j] = m;
				// printf("a[j]=%d_", a[j]);
				j++;
				vis[m+5000] = 1;
			}
		}

		// printf("\n");

		sort(a,a+j);
		printf("%d", j);
		for (int i = 0; i < j; ++i)
		{
			printf(" %d", a[i]);
		}
		printf(" \n");
	}
	return 0;
}
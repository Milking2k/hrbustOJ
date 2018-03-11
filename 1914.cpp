#include <iostream>
#include <cstdio>
// #define maxn 1e5+1
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a[100001];
	while(~scanf("%d", &n))
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &a[i]);
		}
		int t;
		scanf("%d", &t);
		while(t--)
		{
			int m;
			int i;
			int cnt=1e6;
			scanf("%d", &m);
			for (i = 0; i < n; ++i)
			{
				if (m < a[i] && a[i] < cnt)
				{
					cnt = a[i];
					// printf("%d\n", a[i]);
					// break;
				}
			}
			
			if (cnt == 1e6)
			{
				printf("Orz\n");
			}else
				printf("%d\n", cnt);
		}
	}
	return 0;
}
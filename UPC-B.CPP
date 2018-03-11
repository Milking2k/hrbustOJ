// wa

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	int a[100005];
	int ans[100005];
	int an;
	int next=0;
	while(~scanf("%d%d", &n, &k))
	{
		next = 0;
		memset(ans,0,sizeof(ans));
		memset(a,0,sizeof(a));
		an=0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			// printf("%d\n", a[i]);
		}
		for (int i = 0; i <= n-k; i = i+k)
		{
			for (int j = 0; j < k; ++j)
			{
				if (a[i+j+k] == 0)
				{
					for (int h = 0; h < k; ++h) an += ans[h];
					printf("%d\n", an);
					next = 1;
					break;
				}
				if(a[i+j] + a[i+j+k] >= ans[j])
					ans[j] = a[i+j] + a[i+j+k];
			}
			if (next)
			{
				break;
			}
		}
	}
	return 0;
}
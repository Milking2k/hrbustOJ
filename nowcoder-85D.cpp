#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <cmath>
using namespace std;
// fixed << setprecision(2)
int main(int argc, char const *argv[])
{
	int n,m;
	while(cin >> n >> m)
	{
		int a[505],b[505];
		int ans[250000];
		memset(ans,0,sizeof(ans));
		for (int i = 0; i <= n; ++i)
		{
			cin >> a[i];
			// printf("%d ", a[i]);
		}
		// printf("\n");
		for (int i = 0; i <= m; ++i)
		{
			cin >> b[i];
			// printf("%d ", b[i]);
		}
		// printf("\n");
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 0; j <= m; ++j)
			{
				ans[i+j] += a[i]*b[j];
			}
		}
		for (int i = 0; i < m+n+1; ++i)
		{
			if (i==0)
			{
				printf("%d", ans[i]);
			}else{
				printf(" %d", ans[i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
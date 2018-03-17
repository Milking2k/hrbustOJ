#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	printf("1\n");
	int x,y,z,n;
	int a[1005];
	int b[1005];
	int c[1005];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	while(cin >> x >> y >> z >> n)
	{
		int tx,ty,tz;
		for (int i = 0; i < n; ++i)
		{
			cin >> tx >> ty >> tz;
			a[tx-1] = 1;
			b[ty-1] = 1;
			c[tz-1] = 1;
		}

		for (int i = y-1; i >= 0; --i)
		{
			for (int j = 0; j < x; ++j)
			{

				printf("  oo:%d %d %d:", a[j] , b[i] , c[0]);
				if (a[j] && b[i] && c[0])
				{
					printf("x");
				}else{
					printf(".");
				}
			}
			printf(" ");
			for (int j = 0; j < z; ++j)
			{
				printf("  pp:%d %d %d", a[0] , b[i] , c[j]);

				if (a[0] && b[i] && c[j])
				{
					printf("x");
				}else{
					printf(".");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
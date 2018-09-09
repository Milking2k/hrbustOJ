#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int a[5];
	while(~scanf("%d%d%d%d%d",&a[0],&a[1],&a[2],&a[3],&a[4]))
	{
		if ((2*a[3] == a[4]+a[2]) &&
			(2*a[1] == a[0]+a[2]) &&
			(2*a[2] == a[1]+a[3]) )
		{
			int x = a[4]-a[3];
			printf("%d %d %d %d %d \n", a[4]+x, a[4]+2*x, a[4]+3*x, a[4]+4*x, a[4]+5*x);
		}
		else if ((a[3]*a[3] == a[2]*a[4]) &&
				 (a[1]*a[1] == a[0]*a[2]) &&
				 (a[2]*a[2] == a[1]*a[3]) )
		{
			int x = a[4]/a[3];
			printf("%d %d %d %d %d \n", a[4]*x, a[4]*x*x, a[4]*x*x*x, a[4]*x*x*x*x, a[4]*x*x*x*x*x);
		}
		else if ((a[4] == a[3] + a[2]) &&
				 (a[3] == a[2] + a[1]) &&
				 (a[2] == a[1] + a[0]))
		{
			printf("%d %d %d %d %d \n", a[4]+a[3], 2*a[4]+a[3], 3*a[4]+2*a[3], 5*a[4]+3*a[3], 8*a[4]+5*a[3]);
		}else{
			printf("None\n");
		}
	}
	return 0;
}

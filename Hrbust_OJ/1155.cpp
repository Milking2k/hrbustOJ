#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m))
	{
		if (m == 2 && ((n%4 == 0 && n%100 != 0) || n%400 == 0))
		{
				printf("29\n");
				continue;
		}
		else{
			if (m == 2)
			{
				printf("28\n");
				continue;
			}
			if (m<=7 && m%2 == 1)
			{
				printf("31\n");
			}
			else if (m<=7 && m%2 == 0)
			{
				printf("30\n");
			}
			else if (m>7 && m%2 == 1)
			{
				printf("30\n");
			}
			else if (m>7 && m%2 == 0)
			{
				printf("31\n");
			}
		}
	}
	return 0;
}

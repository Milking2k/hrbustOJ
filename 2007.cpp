#include <iostream>
#include <cstdio>
using namespace std;
int main()
{ 
					   // 31 28 31 30  31  30  31  31  30  31  30  31
	int month[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
	int a,b;
	while(~scanf("%d%d", &a,&b))
	{
		if (a==2 && b==29)
		{
			printf("11540\n");
			continue;
		}
		printf("%d\n", 10*(month[a-1] + b - 1));
	}
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int x,y;
	while(~scanf("%d%d",&x,&y))
	{
		if (x<0 || y<0 || y%2 == 1 || (y/2)-x < 0 || 2*x-(y/2) < 0)
		{
			printf("something wrong\n");
			continue;
		}
		printf("chicken:%d rabbit:%d\n", 2*x-(y/2),(y/2)-x);
	}
	return 0;
}
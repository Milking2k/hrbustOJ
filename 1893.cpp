// unfinished
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a1,b1,a2,b2,a3,m;
	while(~scanf("%d %d %d %d %d %d",&a1,&b1,&a2,&b2,&a3,&m))
	{
		if ((a3*(b1-b2) - a1*b1 + a2*b2) && (a2*b2*(b1-b2) - b2*(a1*b1-a2*b2)) >= (a3*(b1-b2) - a1*b1 + a2*b2) * m)
		{
			printf("YES\n");
		}else if(-(a3*(b1-b2) - a1*b1 + a2*b2) && )
		{

		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
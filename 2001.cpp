#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x1,y1,x2,y2,x3,y3;
		scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
		// printf("%d_%d\n", (y2-y1)*(x3-x1),(x2-x1)*(y3-y1));
		if ((y2-y1)*(x3-x1) == (x2-x1)*(y3-y1))
		{
			printf("fail\n");
			continue;
		}
		// printf("%.2f\n", ((x1*(y2-y3))+(x2*(y3-y1))+(x3*(y1-y2)))/2.0);
		printf("%.2f\n", (abs(x1*y2 + x2*y3 + x3*y1 - x1*y3 - x2*y1 - x3*y2))/2.0);
		// printf("%.2f\n", (y1-y3)*(x2-x1)/2.0+(x3-x1)*(y2-y3)/2.0-(x1-x3)*(y1-y3)/2.0);

	}
	return 0;
}
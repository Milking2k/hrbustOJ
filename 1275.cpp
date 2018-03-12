#include <iostream>
#include <cstdio>
#include <cctype>
#include <cmath>
using namespace std;
int main()
{
	// struct Point points[2];
	int x1,y1,x2,y2;
	int speed;
	while(~scanf("%d%d%d%d%d", &x1,&y1,&x2,&y2,&speed))
	{
		y1 = -1*y1;
		double distance = sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
		printf("%.2f\n", distance/(1.0*speed));
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		double x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		double ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
		printf("%.2f\n", ans);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct POINT
{
	double x,y;	
}p[7];


int main(int argc, char const *argv[])
{
	for (int i = 0; i < 3; ++i)
	{
		scanf("%lf%lf",&p[i].x,&p[i].y);
	}
	POINT midPoint;
	midPoint.x = (double)(p[0].x+p[2].x)/2;
	midPoint.y = (double)(p[0].y+p[2].y)/2;
	// cout << midPoint.x << " " << midPoint.y << endl;

	// printf("%.18f\n", (double)(p[0].x-p[2].x));
	// printf("%.18f\n", (double)(p[1].y-midPoint.y));
	if(!(double)(p[0].x-p[2].x) && !(double)(p[1].y-midPoint.y) && (p[1].x - midPoint.x))
	{
		return printf("YES\n"),0;
 	}
	double slopeAC = (double)(p[0].y-p[2].y)/(double)(p[0].x-p[2].x);
	double slopeB = (p[1].x - midPoint.x)/(double)(p[1].y-midPoint.y);
	cout << slopeAC<< " " << slopeB << endl;
	printf("%.16f %.16f\n", slopeAC,slopeB);

	if(abs(slopeAC+slopeB) <= 1e-10 || slopeAC == -slopeB) printf("YES\n");
	else printf("NO\n");

	return 0;
}
/*
0 1000000000 1 0 0 -1000000000
*/
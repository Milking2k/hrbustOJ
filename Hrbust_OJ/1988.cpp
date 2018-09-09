#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	double a,b;
	// int n=0;
	while(~scanf("%lf%lf", &a,&b))
	{
		printf("%.f\n", a-b);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cmath>
#define PI acos(-1)
using namespace std;
int main(int argc, char const *argv[])
{
	double a,b;
	int n=0;
	while(~scanf("%lf%lf",&a,&b))	
	{
		if (n){
			printf("\n");
		}
		printf("%.0f\n", a+b);
		n=1;
	}
	return 0;
}

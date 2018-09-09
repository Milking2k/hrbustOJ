#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	long int  a,b,r1,r2;
	while(~scanf("%ld%ld%ld%ld", &a,&b,&r1,&r2))
	{
		if ( a>=2*r1 && a>=2*r2 && b>=2*r2 && b>=2*r1 && ((a-r1-r2)*(a-r1-r2) + (b-r1-r2)*(b-r1-r2) >= (r1+r2)*(r1+r2)))
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
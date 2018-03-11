#include <iostream>
#include <cstdio>
#include <cmath>
#define PI acos(-1)
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))	
	{
		(4*a*a < b*b + c*c) ? printf("NO\n") : printf("YES\n");
	}
	return 0;
}
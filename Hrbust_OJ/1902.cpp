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
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if ((abs(a-b) >= c) || (abs(a-c) >= b) || (abs(c-b) >= a))
		{
			printf("it's not a triangle!\n");
			continue;
		}
		double hfC = (a+b+c)/2.0;
		double ans = sqrt(hfC*(hfC-a)*(hfC-b)*(hfC-c));
		printf("%.2f\n", ans);
	}
	return 0;
}

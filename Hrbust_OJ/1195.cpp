#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		// printf("%.0f\n", n*(n+1)*(n+2)/6.0);
		int sum = 0;
		for (int i = 1; i <= n; i = i+2)
		{
			sum += i*i;
		}
		printf("%d\n", sum);
	}
	return 0;
}
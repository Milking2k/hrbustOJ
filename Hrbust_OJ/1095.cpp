#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	long long int n;
	while(~scanf("%lld",&n))
	{
		long long int sum = 0;
		sum = 4*n*n-4*n+2;
		if (n==0)
		{
			printf("1\n");
		}else{
			printf("%lld\n", sum);
		}
	}
	return 0;
}
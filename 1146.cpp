#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = n-i-1; j > 0; --j)
			{
				printf(" ");
			}
			for (int j = 0; j < 10+2*i; ++j)
			{
				printf("i");
			}
			printf("\n");
		}
	}
	return 0;
}
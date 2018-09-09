#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a;
	while(~scanf("%d",&a))
	{
		if (a<3)
		{
			printf("0\n");
			continue;
		}
		int n=1;
		for (int i = 2; i < a; ++i)
		{	
			if (a%i == 0 && a/i > 2)
			{
				n++;
			}
		}
		printf("%d\n", n);
	}
	return 0;
}
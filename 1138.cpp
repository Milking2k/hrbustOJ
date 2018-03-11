#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a,b;
	while(~scanf("%d%d",&a,&b))
	{
		if (a>b)
		{
			a = a+b;
			b = a-b;
			a = a-b;
		}
		for (int i = a; i > 0 ; --i)
		{
			if (a%i == 0 && b%i == 0)
			{
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
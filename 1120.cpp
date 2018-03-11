#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n) && n)
	{
		if (9 == n)
		{
			printf("1\n");
			continue;
		}
		int x=1;
		for (int i = n; i > 0; --i)
		{
			// printf("action\n");
			if (n%i == 0 && 9%i == 0)
			{
				x = i;
				break;
			}
		}
		printf("%d/%d\n", n/x, 9/x);
	}
	return 0;
}
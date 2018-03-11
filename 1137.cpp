#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		if (n < 3)
		{
			printf("%d\n",n);
			continue;
		}
		int solution = 0;
		for (int i = 0; i < n; ++i)//1
		{
			for (int j = 0; j < n; ++j)//2
			{
				for (int k = 0; k < n; ++k)//3
				{
					if (i + 2*j + 3*k == n)
					{
						solution++;
					}
				}
			}
		}
		printf("%d\n", solution);

	}
	return 0;
}
wroning!
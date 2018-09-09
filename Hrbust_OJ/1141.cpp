#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int p,q;
		scanf("%d%d", &p,&q);
		{
			for (int i = 0; i < q; ++i)
			{
				printf(">+");
				for (int i = 0; i < p-2; ++i)
				{
					printf("-");
				}
				printf("+>");
				printf("\n");
			}
			// printf("\n");
		}
	}
	return 0;
}
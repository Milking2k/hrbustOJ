#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a,b;
		scanf("%d%d", &a, &b);
		for (int i = 0; i < b; ++i)
		{
			printf(">+");
			for (int j = 0; j < a-2; ++j)
			{
				printf("-");
			}
			printf("+>\n");
		}
	}
	return 0;
}
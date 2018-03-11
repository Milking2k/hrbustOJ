#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	char a[11] = {'E','E','E','E','E','E','D','C','B','A','A'};
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i)
		{
			int num;
			scanf("%d",&num);
			// if (i==0)
			// {
			// 	printf("%c", a[num/10]);
			// 	continue;
			// }
			printf("%c ", a[num/10]);
		}
		printf("\n");
	}
	return 0;
}
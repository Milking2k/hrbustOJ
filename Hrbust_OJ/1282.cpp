#include <stdio.h>
int main()
{
	int i, j;
	int n = 40111;
	int ans;
	for (i = 1; i <= n; i++)
	{
		ans = 1;
		for (j = 1; j <= i; j++)
		{
			ans *= j;
			ans %= 40111;
		}
		printf("%d\n",ans);
	}
	return 0;
}
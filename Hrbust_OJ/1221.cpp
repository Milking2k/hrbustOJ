#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b;
	while(~scanf("%d%d", &a,&b))
	{
		int ans = a;
		if (a%10 == 0)
		{
			printf("0\n");
			continue;
		}
		for (int i = 1; i < b; ++i)
		{
			if (ans>10)
			{
				ans = ans%10;
			}
			ans = ans*a;
		}
		(ans > 10) ? printf("%d\n", ans%10) : printf("%d\n", ans);
	}
	return 0;
}
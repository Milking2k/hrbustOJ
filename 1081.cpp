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
		scanf("%d%d",&p,&q);
		if (p%2 == 1)
		{
			printf("PleaseCallMeFlash!\n");
		}
		else if (p%2 == 0 && q%2 == 0)
		{
			printf("JiaoZhuV5!\n");
		}
		else if (p%2 == 0 && q%2 == 1)
		{
			printf("Orz!\n");
		}
	}
	return 0;
}
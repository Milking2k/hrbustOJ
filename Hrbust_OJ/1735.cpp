#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a;
		scanf("%d",&a);
		if (a && a%16 == 0)
		{
			printf("Yes\n");
			continue;
		}
		printf("No\n");
	}
	return 0;
}

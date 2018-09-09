#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	while(n--)
	{
		int a,b;
		scanf("%d%d", &a,&b);
		if (a>b)
		{
			printf("YES\n");
		}else
		{
			
			printf("NO\n");
		}
	}
	return 0;
}
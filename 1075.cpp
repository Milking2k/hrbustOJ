#include <iostream>
#include <cstdio>
#include <cctype>
#include <cmath>
using namespace std;
int main()
{
	int a,b;
	while(~scanf("%d%d", &a,&b))
	{
		if (a%(b+1) == 0)
		{
			printf("LeyniV5!\n");
		}
		else{
			printf("JiaozhuV5!\n");
		}
	}
	return 0;
}
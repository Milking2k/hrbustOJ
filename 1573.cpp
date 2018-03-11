#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int x;
	while(~scanf("%d",&x))
	{
		if (x<=3)
		{
			printf("1\n");
			continue;
		}
		printf("%d\n", x-2);
	}
	return 0;
}

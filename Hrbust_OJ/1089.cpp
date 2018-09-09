#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		printf("8\n%d\n%d\n",12*(n-2), 6*(n-2)*(n-2));
	}
	return 0;
}
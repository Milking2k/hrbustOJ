#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	unsigned int x = 1;
	int n;
	while(~scanf("%d", &n))
	{
		printf("%d\n", x+n);
	}
	return 0;
}
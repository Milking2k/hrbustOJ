#include <iostream>
#include <cstdio>
using namespace std;
unsigned int m=2147483648;
int main(int argc, char const *argv[])
{
	// printf("%\n", M);
	int x;
	
	while(~scanf("%d", &x))
	{
		m=2147483648;
		while(m)
		{
			printf("%d", x/m);
			x %= m;
			m /= 2;
		}
		printf("\n");
	}
	// printf("\n");
	// cout<< M;
	return 0;
}
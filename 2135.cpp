#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d", &n))
	{
		printf("%d\n", 9*(n/16) + 3*((n%16)/8) + (((n%16)%8) / 4));
	}
	return 0;
}
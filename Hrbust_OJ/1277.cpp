#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d", &n))
	{
		int x1 = n%3;
		int x2 = x1;
		for (int i = 0; i < 4; ++i)
		{
			x2 = (x2*x1)%3;
		}
		printf("%d\n", x2);
	}
	return 0;
}
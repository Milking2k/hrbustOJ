#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
	for (int n = 21; n < 10000; ++n)
	{	
		if ((ceil(sqrt(n+100)) == floor(sqrt(n+100))) &&
			(ceil(sqrt(n+268)) == floor(sqrt(n+268))))
		{
			printf("%d\n", n);
		}
	}
	return 0;
}
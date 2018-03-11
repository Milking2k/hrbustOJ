#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int times;
	cin >> times;
	while(times--)
	{
		int n;
		int sum=0;
		cin >> n;
		int r = (int)sqrt(1.0 * n);
		for (int i = 1; i <= r; ++i)
		{
			if (n%i == 0)
			{
				sum++;
			}
		}
		if (r*r == n)
		{	
			printf("%d\n", 2*sum - 1);
			continue;
		}
		printf("%d\n", 2*sum);
	}
	return 0;
}
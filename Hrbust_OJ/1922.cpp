#include <iostream>
#include <cstdio>
using namespace std;

int jc(int x)
{
	int ans=1;
	for (int i = 1; i <= x; ++i)
	{
		ans *= i;		
	}
	// printf("%d\n", ans);
	return ans;
}
int main(int argc, char const *argv[])
{
	// int p;
	// scanf("%d", &p);
	// int ct = p;

	// printf("%d\n", jc(9));
	// jc(15);
	for (int i = 1; i < 2147483647; ++i)
	{
		int sum = 0;
		int tmp = i;
		int ct = tmp%10;
		while(ct)
		{
			sum += jc(ct);
			tmp /= 10;
			ct = tmp % 10;
			if (sum > i)
				break;
		}
		if (i == sum)
		{
			printf("%d\n", i);
		}
	}
		
	return 0;
}
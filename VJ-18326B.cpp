#include <iostream>
#include <cstdio>
using namespace std;
// attention:两个负数的乘积也可以是正数。所以不能直接只乘正数。
int main(int argc, char const *argv[])
{
	int n;
	int count=0;
	while(cin >> n)
	{
		count++;
		int a[20];

		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			// printf("%d  ", a[i]);
		}

		long long int sum=1;
		long long int maxn = 0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = i; j < n; ++j)
			{
				sum = 1;
				for (int k = i; k <= j; ++k)
				{
					sum *= a[k];
				}
				// printf("%lld\n", maxn);
				if (sum > maxn)
				{
					maxn = sum;
				}
			}
		}
		printf("Case #%d: The maximum product is %lld.\n\n", count, maxn);

	}
	return 0;
}
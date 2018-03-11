#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n)
	{
		int a[102];
		int sum=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
			sum += a[i];
		}
		double sum2=0;
		double anverage = sum/(1.0*n);
		// printf("anverage=%.3f\n", anverage);
		for (int i = 0; i < n; ++i)
		{
			sum2 += (anverage-a[i])*(anverage-a[i]);
		}
		// printf("%.3f\n", sum2);
		double ans = sqrt(sum2/(1.0*n));
		printf("%.4f\n", ans);
	}
	return 0;
}
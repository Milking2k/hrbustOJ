#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
	int times;
	
	while(~scanf("%d", &times))
	{
		int sum =0;
		int cnt;
		for (int i = 0; i < times; ++i)
		{
			scanf("%d", &cnt);
			sum += cnt;
		}
		printf("%d\n", sum);
	}
	return 0;
}
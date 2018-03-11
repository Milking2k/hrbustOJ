#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while(~scanf("%d",&n))
	{
		int sum = n;
		for (int i = 0; i < 4; ++i)
		{
			scanf("%d",&n);
			sum += n;
		}
		if (sum == 0)
		{
			printf("-1\n");
		}
		else if (sum%5 == 0)
		{
			printf("%d\n", sum/5);
		} else{
			printf("-1\n");
		}

	}
	return 0;
}
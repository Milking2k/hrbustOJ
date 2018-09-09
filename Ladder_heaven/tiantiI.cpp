#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,t;
	while(cin >> n >> t)
	{
		// int cnt;
		int a[100005];
		int yanSum = 0;
		int yanpos = 0;
		int nathanSum = 0;
		int nathanPos = 0;
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i];
			yanSum += a[i];
			// printf("%d ",i);
			if (yanSum > t)
			{
				yanpos = i;
			}
		}
		printf("%d\n", yanpos);
		// printf("out\n");
		for (int i = n; i >=1; --i)
		{
			// printf("%d ", i);
			nathanSum += a[i];
			if (nathanSum > t)
			{
				nathanPos = n-i+1;
			}
		}
		printf("%d\n", nathanPos);

		if (yanpos > nathanPos)
		{
			printf("Yan\n");
		}else if (yanpos < nathanPos)
		{
			printf("Nathan\n");
		}else{
			printf("Empate\n");
		}


	}
	return 0;
}

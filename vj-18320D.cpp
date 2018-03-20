#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int m;
	while(cin >> m)
	{
		if (m<=153)
		{
			printf("153\n");
		}else if (m <= 370)
		{
			printf("370\n");
		}else if (m == 371)
		{
			printf("371\n");
		}else if (m <= 407)
		{
			printf("407\n");
		}//1634
		else{
			printf("1634\n");
		}
	}
	// for (int i = 1; i < 10000; ++i)
	// {
	// 	int n = i;
	// 	int ans = 0;
	// 	// int count=0;

	// 	while(n)
	// 	{
	// 		int a = n%10;
	// 		ans += a*a*a;
	// 		n/=10;
	// 	}
	// 	if (ans == i)
	// 		printf("%d\n", ans);
	// }
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
// int foo(int x)
// {
// 	if (x == 0)
// 		return 5;
// 	else if (x == 1)
// 	{
// 		return 13;
// 	}
// 	return foo(x-2) + foo(x-1);
// }
int main()
{
	int n;
	while(~scanf("%d", &n))
	{
		if ((n-2)%4 == 0)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}

	return 0;
}
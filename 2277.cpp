#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int times;
	scanf("%d", &times);
	while(times--)
	{
		int buyDay = 0;
		int buyNum = 0;
		int a,b;
		for (int i = 1; i < 8; ++i)
		{
			scanf("%d%d",&a,&b);
			if (a+b > 8 && a+b > buyNum)
			{
				buyDay = i;
				buyNum = a+b;
			}
		}
		printf("%d\n", buyDay);
	}
	return 0;
}
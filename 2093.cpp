#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			int x = i*j;
			if (x>=10)
			{
				for (int k = 0; k <=9; ++k)
				{
					printf("%d%d%d%d\n", i,j,k,x);
				}
			}
			else{
				for (int k = 0; k <=9; ++k)
				{
					printf("%d%d%d0%d\n", i,j,k,x);
				}
			}
		}
	}
	return 0;
}
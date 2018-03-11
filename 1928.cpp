#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	// int a[51] = {0};
	int n;
	while(cin >> n)
	{
		int hst = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				for (int k = 1; k <= n; ++k)
				{
					if ((i+j+k)>hst && ((i+j)%2 ==0 && (j+k)%3 ==0 && (i+j+k)%5 == 0))
					{
						hst = i+j+k;
					}
				}
			}
		}
		if(hst){
			printf("%d\n", hst);
			continue;
		}
		printf("Impossible\n");

	}
	
	return 0;
}
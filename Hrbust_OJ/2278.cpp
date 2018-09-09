#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--)
	{
		int a[3][3];
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				cin >> a[j][i];
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				printf("%d", a[i][j]);
				if (j!=2)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
char zhu[1001][1001],fu[1001][1001],zuo[1001][1001];
int main(int argc, char const *argv[])
{
	int X,Y,Z,n;
	cin >> X >> Y >> Z >> n;
	for (int i = 0; i < 1000; ++i)
	{
		for (int j = 0; j < 1000; ++j)
		{
			zhu[i][j] = '.';
			fu[i][j] = '.';
			zuo[i][j] = '.';
		}
	}
	for (int i = 0; i < Y; ++i)
	{
		zhu[i][X] = 0;
		zuo[i][Z] = 0;
	}
	for (int i = 0; i < Z; ++i)
	{
		fu[i][X] = 0;
	}
	int x,y,z;
	for (int i = 0; i < n; ++i)
	{
		cin >> x >> y >> z;
		zhu[Y-y][x-1] = 'x'; 
		zuo[Y-y][z-1] = 'x'; 
		 fu[z-1][x-1] = 'x'; 
	}
	for (int i = 0; i < Y; ++i)
	{
		printf(zhu[i]);
		putchar(' ');
		printf(zuo[i]);
		putchar('\n');
	}
	putchar('\n');
	for (int i = 0; i < Z; ++i)
	{
		puts(fu[i]);
	}

	
	return 0;
}
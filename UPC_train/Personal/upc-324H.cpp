#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	char a[103][103];
	int n,m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (a[i][j] != '*')
			{
				int lx = max(0,i-1);
				int rx = min(n-1,i+1);
				int ly = max(0,j-1);
				int ry = min(n-1,j+1);
				int count=0;
				for (int k = lx; k <= rx; ++k)
				{
					for (int l = ly; l <= ry; ++l)
					{
						if (a[k][l] == '*')
						{
							count++;
						}
					}
				}
				a[i][j] = count+'0';
				// printf("lx:%d rx:%d ly:%d ry:%d count:%d a[%d][%d]=%c\n", lx,rx,ly,ry,count,i,j,a[i][j]); 
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%c", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
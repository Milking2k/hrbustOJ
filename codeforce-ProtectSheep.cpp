#include <iostream>
#include <cstdio>

using namespace std;
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
typedef long long ll;
int main(int argc, char const *argv[])
{
	int n,m;
	char s[505][505];
	while(cin >> n >> m)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				cin >> s[i][j];
			}
		}
		int flag = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (s[i][j] == 'S')
				{
					for (int k = 0; k < 4; ++k)
					{
						int tx = i + dir[k][0];
						int ty = j + dir[k][1];

						if (0 < tx && tx <= n && 0 < ty && ty <= m )
						{
							// printf("-%c-", s[tx][ty]);
							if (s[tx][ty] == 'W')
							{
								flag = 1; break;
							}
						}
					}
					// printf("\n");
				}
			}
		}
		if (flag)
		{
			printf("No\n");
		}else{
			printf("Yes\n");
			for (int i = 1; i <= n; ++i)
			{
				for (int j = 1; j <= m; ++j)
				{
					if (s[i][j] == '.')
					{
						printf("D");
					}else{
						printf("%c", s[i][j]);
					}
				}
				printf("\n");
			}
		}

	}
	return 0;
}
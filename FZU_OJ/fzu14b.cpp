#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		int pos1x,pos1y,pos2x,pos2y;
		for (int i = 1; i <= 4; ++i)
		{
			for (int j = 1; j <= 8; ++j)
			{
				char ch;
				scanf("%c",&ch);
				if(ch=='*')
				{
					pos1x = i,pos1y = j;
					// printf("1i:%d j:%d\n", i,j);
				}
				else if(ch=='.')
				{
					pos2x = i,pos2y = j;
					// printf("2i:%d j:%d\n", i,j);
				}
			}
			getchar();
		}
		int cnt = abs(pos1x-pos2x)+abs(pos1y-pos2y);
		// printf("%d\n", cnt);
		if(cnt&1) printf("Red win\n");
		else printf("Black win\n");

	}
	return 0;
}
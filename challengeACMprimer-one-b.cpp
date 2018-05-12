#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int w,h;
int stx,sty;
int edx,edy;
int emt[27][27];
int dir1[4] = {1,0,0,-1};
int dir2[4] = {0,1,-1,0};
int vis[27][27];
int ans;
struct node
{
	int x,y;
};
queue<node> que;

int check(int x, int y) {
    if(emt[x][y] == 0 || emt[x][y] == 2 ) return 1; 
    else if(emt[x][y] == -1 || emt[x][y] == 1) return 2;
    else return 3;
}

void dfs(int x,int y, int t)
{
	if(x == edx && y == edy || t > 10) {
        ans = (t < ans ? t : ans);
    }
    else {
        for(int i = 0; i < 4; i++) {
            int tx = x, ty = y;
            if(check(tx + dir1[i], y + dir2[i]) != 2) {
                while(check(tx + dir1[i], ty + dir2[i]) == 1) {
                    tx += dir1[i], ty += dir2[i];
                }
                if(emt[tx + dir1[i]][ty + dir2[i]] == 1) {
                    emt[tx + dir1[i]][ty + dir2[i]] = 0;
                    t++;    
                    dfs(tx, ty, t);
                    --t;    
                    emt[tx + dir1[i]][ty + dir2[i]] = 1;
                }
                else if(emt[tx + dir1[i]][ty + dir2[i]] == 3) {
                    t++;
                    dfs(tx + dir1[i], ty + dir2[i], t);
                    --t;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d%d",&w,&h) && w && h)
	{
		// getchar();
		// init
		memset(vis,0,sizeof(vis));
		ans=0;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				scanf("%d",&emt[i][j]);				
				if(emt[i][j]=='2') stx=i,sty=j;
				if(emt[i][j]=='3') edx=i,edy=j;
			}
			// getchar();
		}
		for (int i =0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				printf("%d",emt[i][j]);			
			}
			printf("\n");
		}
		dfs(stx,sty,0);
		printf("%d\n", ans > 10 ? -1 : ans);
	}

	return 0;
}
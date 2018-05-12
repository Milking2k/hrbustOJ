#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

int w,h;
int stx,sty;
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
void dfs()
{
	node stpos;
	stpos.x = stx;
	stpos.y = sty;
	que.push(stpos);
	while(!que.empty())
	{
		node cntnode = que.front();
		que.pop();
		for (int i = 0; i < 4; ++i)
		{
			int cntx = min(max(cntnode.x+dir1[i],0),h-1);
			int cnty = min(max(cntnode.y+dir2[i],0),w-1);
			
			if(emt[cntx][cnty]=='.' && !vis[cntx][cnty])
			{
				// printf("cntx:%d cnty:%d_\n", cntx,cnty);
				stpos.x = cntx;
				stpos.y = cnty;
				que.push(stpos);
				vis[cntx][cnty] = 1;
				ans++;
			}
		}
	}
	printf("%d\n", ans+1);
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d%d",&w,&h) && w && h)
	{
		getchar();
		// init
		memset(vis,0,sizeof(vis));
		ans=0;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				scanf("%c",&emt[i][j]);				
				if(emt[i][j]=='@') stx=i,sty=j;
			}
			getchar();
		}
		// for (int i =0; i < h; ++i)
		// {
		// 	for (int j = 0; j < w; ++j)
		// 	{
		// 		printf("%c",emt[i][j]);			
		// 	}
		// 	printf("\n");
		// }
		dfs();

	}

	return 0;
}
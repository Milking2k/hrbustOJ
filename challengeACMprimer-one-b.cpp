#include<stdio.h>
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ei,ej;
int map[25][25];
int w,h,steps,min;
#define MAX 99999999
void dfs(int si,int sj)
{
	int i,pi,pj;
	if(steps>=10) return ;

	for(i=0;i<4;i++)
	{		
		pi=si,pj=sj;
		while(1)
		{
			pi+=dir[i][0];
			pj+=dir[i][1];
			if(pi<=0||pi>h||pj<=0||pj>w) break;//如果越界，选择其他方向
			if(pi==ei&&pj==ej) 
			{
				steps++;
				if(min>steps) min=steps;
				steps--;
				return;
			}
			else if(map[pi][pj]==1)//如果遇到障碍物
			{

				if(pi-dir[i][0]!=si||pj-dir[i][1]!=sj)//如果不是起来
				{
					map[pi][pj]=0;//消除障碍物
					steps++;//前进一步
					dfs(pi-dir[i][0],pj-dir[i][1]);//递归查找该点到终点的最小步数
					map[pi][pj]=1;//还原障碍物
					steps--;//还原步数
				}
				break;
			}
		}
	}
}		
int main()
{
	int si,sj,i,j;
	while(scanf("%d%d",&w,&h)==2&&(w||h))
	{
		for(i=1;i<=h;i++)//输入并找到起点和终点
			for(j=1;j<=w;j++)
			{
				scanf("%d",&map[i][j]);
				if(map[i][j]==2)
					si=i,sj=j;
				else if(map[i][j]==3)
					ei=i,ej=j;
			}
			min=MAX;//记录最小步数
			steps=0;//初始化步数
			dfs(si,sj);//深搜
			if(min==MAX) puts("-1");
			else printf("%d\n",min);
	}
	return 0;
}

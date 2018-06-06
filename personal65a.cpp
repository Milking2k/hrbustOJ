#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct node
{
    int x,y;
};

int n,stx,sty,edx,edy;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char emt[1007][1007];
int vis[1007][1007];
bool flag = false;

void bfs()
{
    memset(vis,-1,sizeof(vis));
    queue<node> qu;

    qu.push((node){stx,sty});
    vis[stx][sty] = 0;
    flag = false;

    while(!qu.empty())
    {
        node cnt = qu.front();
        qu.pop();

        for(int i=0;i<4;i++)
        {
            int nowx = cnt.x+dir[i][0];
            int nowy = cnt.y+dir[i][1];


            if(nowx > n || nowx < 1 || nowy > n || nowy < 1 ) continue;
            if(vis[nowx][nowy]==-1 && emt[nowx][nowy]!='#')
            {

                vis[nowx][nowy] = vis[cnt.x][cnt.y] + 1;
                if(emt[nowx][nowy]=='E')
                {
                    flag = true;
                    break;
                }
                qu.push((node){nowx,nowy});
            }
        }
        if(flag) break;
    }
}

int main()
{
    while(~scanf("%d",&n))
    {
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%c",&emt[i][j]);
                if(emt[i][j] == 'S') stx=i,sty=j;
                if(emt[i][j] == 'E') edx=i,edy=j;
            }
            getchar();
        }
//        for(int i=1;i<=n;i++)
//        {
//            for(int j=1;j<=n;j++)
//                printf("%c",emt[i][j]);
//            printf("\n");
//        }

        bfs();
        printf("%d\n",vis[edx][edy]);

    }
    return 0;
}

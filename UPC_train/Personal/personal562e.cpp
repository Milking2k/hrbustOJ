#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int dp[1007][2];
int emt[1007];
int vis[1007];
int n,m;

vector<int> Gh[1007];

void dfs(int x)
{
    dp[x][1]=1;
    vis[x]=1;
    for(int i=0;i<Gh[x].size();i++)
    {
        int now = Gh[x][i];
        if(vis[now]==0)
        {
            dfs(now);
            dp[x][1] += dp[now][0];
            dp[x][0] += max(dp[now][1],dp[now][0]);
        }
    }
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        //init
        for(int i=1;i<=n;i++) Gh[i].clear();
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        memset(emt,-1,sizeof(emt));
        for(int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            Gh[x].push_back(y);
            emt[y]=x;
        }
        int i;
        for(i=1;i<=n;i++)
            if(emt[i]==-1)
            {
                dfs(i);
                break;
            }
        printf("%d\n",dp[i][1]);
    }
    return 0;
}

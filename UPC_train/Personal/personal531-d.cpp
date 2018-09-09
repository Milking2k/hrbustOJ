//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;

// --------------
struct node
{
    int st,to,val;
}edge;

int n;
int d[100007];
vector<node> edge[100007];
int path[100007];

void dfs(int st,int len,int ans)
{
    if() return;

    for(int i=1;i<edge[i].size();i=edge[i].to)
    {

    dfs(i,min())
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&emt[i]);
            if(emt[i]==1)sum++,emt[i]=-1;
            else emt[i]=1;
        }
        if(sum==n)
        {
            printf("%d\n",n-1);
            continue;
        }
        int ans=0;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=max(dp[i-1]+emt[i],0);
            ans = max(ans,dp[i]);
        }
        ans+=sum;
        printf("%d\n",ans);
    }
    return 0;
}

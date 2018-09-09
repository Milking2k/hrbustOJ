#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,dp[maxn][2],fa[maxn],val[maxn];
vector <int>mp[maxn];

void dfs(int now)
{
    dp[now][1]=val[now];
    int ans0=0,ans1=val[now];
    for(int i=0;i<mp[now].size();i++){
        int as=mp[now][i];
        dfs(as);
//        dp[now][0]=max(dp[as][1],dp[as][0]);
//        dp[now][1]+=dp[as][0];
        ans0=max(ans0,max(ans0^dp[as][0],ans0^dp[as][1]));
        ans1=max(ans1,ans1^dp[as][0]);
//        printf("test %d %d %d %d\n",now,as,ans0,ans1);
    }
    dp[now][0]=ans0;
    dp[now][1]=ans1;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int res=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
            mp[i].clear();
            res^=val[i];
        }
        memset(fa,-1,sizeof(fa));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            fa[y]=x;
            mp[x].push_back(y);
        }
        int rt=1;
        while(fa[rt]!=-1)rt=fa[rt];
        dfs(rt);
        int as=max(dp[rt][0],dp[rt][1]);
        int qw=res^as;
//        printf("Test %d %d\n",as,qw);
        if(as>qw)puts("Q");
        else if(as==qw)puts("D");
        else puts("T");
    }
    return 0;
}

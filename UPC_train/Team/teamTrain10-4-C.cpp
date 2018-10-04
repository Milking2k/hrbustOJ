#include <bits/stdc++.h>
using namespace std;
 
const int maxn=1e5+7;
int n,m;
int dp[maxn];
vector<int>mp[maxn];
int in[maxn];
int stk[maxn],top;
 
void dfs(int x,int pre)
{
    bool ok=true;
    for(int i=0;i<mp[x].size();i++){
        int now=mp[x][i];
        if(in[now]<in[x]){
            ok=false;break;
        }
    }
    if(ok){
        dp[x]=1;return ;
    }
    for(int i=0;i<mp[x].size();i++){
        int now=mp[x][i];
        if(in[now]<in[x]){
            dfs(now,x);
            dp[x]=max(dp[x],dp[now]+1);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m)){
        for(int i=0;i<=n;i++)mp[i].clear();
        for(int i=0;i<=n;i++)in[i]=0;
        for(int i=0;i<=n;i++)dp[i]=-1;
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            mp[u].push_back(v);
            mp[v].push_back(u);
            in[u]++;in[v]++;
        }
 
        while(true){
            bool ok=true;
            for(int i=0;i<n;i++){
                if(dp[i]==-1){
                    ok=false;
                    dfs(i,i);
                }
            }
            if(ok)break;
        }
        int ans=0;
        for(int i=0;i<n;i++)ans=max(ans,dp[i]);
        printf("%d\n",ans);
    }
    return 0;
}
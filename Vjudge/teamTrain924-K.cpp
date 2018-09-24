#include <bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;
int a[maxn],b[maxn];
int in[maxn];
vector<int> mp[maxn];
int vis[maxn];
queue<int>q;
vector<int>ans;
void solve(int x)
{
    for(int i=0;i<mp[x].size();i++){
        int now=mp[x][i];
        if(vis[now])continue;
        in[now]--;
        if(in[now]==0)q.push(now);
    }
}
int main()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<=2*n;i++)mp[i].clear();
        for(int i=0;i<=2*n;i++)vis[i]=0;
        for(int i=0;i<=2*n;i++)in[i]=0;
        while(q.size())q.pop();
        ans.clear();

        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            mp[i].push_back(x);
            in[x]++;
        }
        for(int i=n+1;i<=2*n;i++){
            int x;
            scanf("%d",&x);
            mp[i].push_back(x);
            in[x]++;
        }
        for(int i=1;i<=2*n;i++){
            if(in[i]==0)q.push(i);
        }
        while(q.size()){
            int now=q.front();q.pop();
            if(vis[now])continue;
            vis[now]=1;
            int v=mp[now][0];
            ans.push_back(now);
            if(vis[v])continue;
            else{
                vis[v]=1;
                solve(v);
            }
        }

//        puts("");
//        for(int i=1;i<=2*n;i++){
//            printf("%d %d %d\n",i,in[i],vis[i]);
//        }
//        puts("");
        for(int i=1;i<=n;i++){
            if(!vis[i])ans.push_back(i);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();++i){
            if(i)printf(" ");
            printf("%d",ans[i]);
        }
        puts("");
    }
    return 0;
}
/*
5
6 6 6 7 8
1 1 1 2 3
*/
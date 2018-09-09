#include <bits/stdc++.h>
using namespace std;
 
struct Min_cost_flow
{
    int S,T,ans=0;
    int vis[100010],vis2[100010];
    int d[100010],head[100010],to[100010],nextt[100010],w[100010],cost[100010];
    int tot = 2;
    int inf=0x7fffffff;
    void init(int _s,int _t)
    {
        S=_s;T=_t;
        memset(head,0,sizeof(head));
    }
    void add(int u,int v,int cap,int co)
    {
        cost[tot]=co;
        w[tot]=cap;
        to[tot]=v;
        nextt[tot]=head[u];
        head[u]=tot++;
        cost[tot] = -co;
        w[tot]=0;
        to[tot]=u;
        nextt[tot]=head[v];
        head[v]=tot++;
    }
    bool spfa()
    {
        memset(vis,0,sizeof(vis));
        memset(vis2,0,sizeof(vis2));
        for(int i = 1;i<=T;i++)d[i]=inf;
        queue<int> q;
        q.push(S);
        d[S]=0;
        vis[S]=1;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            vis[u]=0;
            for(int i = head[u];i;i=nextt[i])
            {
                int v = to[i];
                if(w[i] && d[v]>d[u]+cost[i])
                {
                    d[v]=d[u]+cost[i];
                    if(!vis[v])
                    {
                        vis[v]=1;
                        q.push(v);
                    }
                }
            }
        }
        return d[T]<inf;
    }
    int dfs(int u,int f)
    {
        if(u==T)
        {
            ans+=d[u] * f;
            return f;
        }
        int res=0;
        vis2[u]=1;
        for(int i=head[u];i;i=nextt[i])
        {
            int v = to[i];
            if (w[i] && !vis2[v] && d[v]==d[u]+cost[i])
            {
                int temp=dfs(v,min(f-res,w[i]));
                w[i] -= temp;
                w[i^1] += temp;
                res += temp;
                if(res == f)return res;
            }
        }
        return res;
    }
    int MCMF()
    {
        while(spfa())dfs(S,inf);
        return ans;
    }
}mcmf;
 
struct node
{
    int a[5];
}A[105],B[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            scanf("%d",&A[i].a[j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++){
            scanf("%d",&B[i].a[j]);
        }
    }
    int s=0,t=n*2+1;
    mcmf.S=s;mcmf.T=t;
    for(int i=1;i<=n;i++){
        mcmf.add(s,i,1,0);
    }
    for(int i=1;i<=n;i++){
        mcmf.add(i+n,t,1,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int res=0;
            if(A[i].a[1]==B[j].a[1]||A[i].a[1]==B[j].a[2]||A[i].a[1]==B[j].a[3]||A[i].a[1]==B[j].a[4])res++;
            if(A[i].a[2]==B[j].a[1]||A[i].a[2]==B[j].a[2]||A[i].a[2]==B[j].a[3]||A[i].a[2]==B[j].a[4])res++;
            if(A[i].a[3]==B[j].a[1]||A[i].a[3]==B[j].a[2]||A[i].a[3]==B[j].a[3]||A[i].a[3]==B[j].a[4])res++;
            if(A[i].a[4]==B[j].a[1]||A[i].a[4]==B[j].a[2]||A[i].a[4]==B[j].a[3]||A[i].a[4]==B[j].a[4])res++;
            mcmf.add(i,j+n,1,4-res);
        }
    }
    int ans=mcmf.MCMF();
    printf("%d\n",ans);
    return 0;
}
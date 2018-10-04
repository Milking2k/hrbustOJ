#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e3+3;
int f[maxn],t[maxn],v[maxn];
int n,m;
map<int,int>mp;

struct edge{
    int x,y,w;
    int id;
    edge(int x=0,int y=0,int z=0,int i=0):x(x),y(y),w(z),id(i){}
}e[maxn];
int N,M;
int fa[maxn];
int getfather(int x) {
    if(x==fa[x]) {
        return x;
    }
    else return fa[x]=getfather(fa[x]);
}
bool cmp(edge a,edge b) {
    return a.w<b.w;
}
int kruscal() {
//    puts("@#!$1");
    sort(e+1,e+1+M,cmp);
    int cnt=N;
    int ans=0;
    for(int i=1;i<=N;i++) {
        fa[i]=i;
    }
    for(int i=1;i<=M;i++) {
        int ta=getfather(e[i].x);
        int tb=getfather(e[i].y);
        if(ta!=tb) {
            fa[ta]=tb;
            ans+=e[i].w;
            mp[e[i].id]=1;
//            puts("@#$");
            if(cnt==1)break;
        }
    }
    return ans;
}
struct Edge{
    int next,to,f;
};
struct Dinic
{
    int s,t;
    Edge e[10000];
    int cnt=2,head[10000]={0};
    int dis[10000]={0};
    Dinic (){}
    void init(int _s,int _t)
    {
        cnt=2;
        s=_s,t=_t;
        memset(head,0,sizeof(head));
    }
    void addedge(int u,int v,int f)
    {
        e[cnt]={head[u],v,f};
        head[u]=cnt++;
        e[cnt]={head[v],u,0};
        head[v]=cnt++;
    }
    bool bfs()
    {
        memset(dis,0,sizeof(dis));
        dis[s]=1;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=head[u];i;i=e[i].next)
            {
                int v=e[i].to;
                if(!dis[v]&&e[i].f>0)
                {
                    dis[v]=dis[u]+1;
                    q.push(v);
                }
            }
        }
        return dis[t]!=0;
    }
    int dfs(int u,int flow)
    {
        if(u==t||flow==0) return flow;
        int flow_sum=0;
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to,f=e[i].f;
            if(dis[v]!=dis[u]+1||f==0) continue;
            int temp=dfs(v,min(flow-flow_sum,f));
            e[i].f-=temp;
            e[i^1].f+=temp;
            flow_sum+=temp;
            if(flow_sum>=flow) break;
        }
        if(!flow_sum) dis[u]=-1;
        return flow_sum;
    }
    int maxflow()
    {
        int ans=0;
        while(bfs())
        {
            while(int temp=dfs(s,0x7fffffff))
                ans+=temp;
        }
        return ans;
    }
}DC;

int main() {
    read(n),read(m);
    N=n;
    for(int i=1;i<=m;i++) {
        read(f[i]),read(t[i]);
        read(v[i]);
        e[++M].w=v[i];
        e[M].x=f[i];
        e[M].y=t[i];
        e[M].id=i;
    }
    int S=0,T=n+1;
    int ss=kruscal();
    int ans=0;
    for(int i=1;i<=m;i++) {
        if(mp[i]==0) {
            DC.init(0,n+1);
            for(int j=1;j<=m;j++) {
                if(v[i] > v[j]){
                    DC.addedge(f[j],t[j],1);
                    DC.addedge(t[j],f[j],1);
                }
            }
            DC.addedge(S,f[i],n);
            DC.addedge(t[i],T,n);
            int ret=DC.maxflow();
            ans+=ret;
        }
    }
    cout<<ans<<endl;
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int mm=333300;
const int mn=1111;
const int oo=1000000000;
int node,src,dest,edge;
int reach[mm],flow[mm],cost[mm],nxt[mm];
int head[mn],dis[mn],q[mn],p[mn],a[mn],x[mn],y[mn];
bool vis[mn];
inline void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0;i<node;++i)head[i]=-1;
    edge=0;
}
inline void addedge(int u,int v,int f,int c)
{
    reach[edge]=v,flow[edge]=f,cost[edge]=c,nxt[edge]=head[u],head[u]=edge++;
    reach[edge]=u,flow[edge]=0,cost[edge]=-c,nxt[edge]=head[v],head[v]=edge++;
}
bool spfa()
{
    int i,u,v,l,r=0,tmp;
    for(i=0;i<node;++i)dis[i]=oo;
    dis[q[r++]=src]=0;
    p[src]=p[dest]=-1;
    for(l=0;l!=r;(++l==mn)?l=0:1)
        for(i=head[u=q[l]],vis[u]=0;i>=0;i=nxt[i])
            if(flow[i]&&dis[v=reach[i]]>(tmp=dis[u]+cost[i]))
            {
                dis[v]=tmp;
                p[v]=i^1;
                if(vis[v])continue;
                vis[q[r++]=v]=1;
                if(r==mn)r=0;
            }
    return p[dest]>=0;
}
int SpfaFlow()
{
    int i,ret=0,delta;
    while(spfa())
    {
        for(i=p[dest],delta=oo;i>=0;i=p[reach[i]])
            if(delta>flow[i^1])delta=flow[i^1];
        for(i=p[dest];i>=0;i=p[reach[i]])
            flow[i]+=delta,flow[i^1]-=delta;
        ret-=delta*dis[dest];
    }
    return ret;
}
int find(int x,int m)
{
    int l=0,r=m;
    while(l<r)
    {
        m=(l+r)>>1;
        if(a[m]==x)return m;
        if(a[m]>x)r=m-1;
        else l=m+1;
    }
    return l;
}
int val[mn];
int main()
{
    int i,u,v,n,k,m,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(m=i=0;i<n;++i)scanf("%d%d%d",&x[i],&y[i],&val[i]),a[m++]=x[i],a[m++]=y[i];
        sort(a,a+m);
        for(v=0,u=1;u<m;++u)
            if(a[u]>a[v])a[++v]=a[u];
        m=v+1;
        prepare(m+2,0,m+1);
        addedge(src,1,k,0);
        addedge(m,dest,k,0);
        for(u=1;u<m;++u)addedge(u,u+1,oo,0);
        for(i=0;i<n;++i)
            addedge(find(x[i],m-1)+1,find(y[i],m-1)+1,1,-val[i]);
        printf("%d\n",SpfaFlow());
    }
    return 0;
}

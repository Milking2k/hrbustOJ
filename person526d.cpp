#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
struct node
{
    int x,y,r;
}points[1007];
 
int xs,ys,st,yt;
int n;
double emt[1007][1007];
//double dist[1007];
//bool vis[1007];
//void dijkstra()
//{
//    fill(ds,ds+n+2,inf);
//    fill(used,used+n+2,false);
//    ds[1]=0;
//    while(1)
//    {
//        int v = -1;
//        for(int i=1;i<=n+2;i++)
//        {
//            if(!used[i] && (v==-1 || ds[i] < ds[v])) v=i;
//        }
//        if(v==-1) break;
//        used[v]=true;
//        for(int i=1;i<=n+2;i++)
//            ds[i]=min(ds[i],ds[v]+emt[v][i]);
//    }
//}
const int INF=0x3f3f3f3f;
const int MAXN=10010;
struct qnode
{
    int v;
    int c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v;
    double cost;
    Edge(int _v=0,double _cost=0):v(_v),cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
double dist[MAXN];
void dijkstra(int n,int start)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)dist[i]=INF;
    priority_queue<qnode>que;
    while(!que.empty())que.pop();
    dist[start]=0;
    que.push(qnode(start,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp=que.top();
        que.pop();
        int u=tmp.v;
        if(vis[u])continue;
        vis[u]=true;
        for(int i=0;i<E[u].size();i++)
        {
            int v=E[tmp.v][i].v;
            double cost=E[u][i].cost;
            if(!vis[v]&& dist[v]>dist[u]+cost)
            {
                dist[v]=dist[u]+cost;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,double w)
{
    E[u].push_back(Edge(v,w));
}
int main()
{
    int xs,ys,xt,yt;
    while(~scanf("%d%d%d%d%d",&xs,&ys,&xt,&yt,&n))
    {
        memset(emt,inf,sizeof(0));
        points[1].x=xs;
        points[1].y=ys;
        points[1].r=0;
        points[n+2].x=xt;
        points[n+2].y=yt;
        points[n+2].r=0;
        for(int i=2;i<=n+1;i++) scanf("%d%d%d",&points[i].x,&points[i].y,&points[i].r);
        n+=2;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(j==i) continue;
//                printf("\n%d %d %d %d\n",points[i].x,points[i].y,points[j].x,points[j].y);
                double cnt = max(sqrt((points[i].x-points[j].x)*(points[i].x-points[j].x)+(points[i].y-points[j].y)*(points[i].y-points[j].y)) - points[i].r-points[j].r,0.0);
                addedge(i,j,cnt);
                addedge(j,i,cnt);
            }
        dijkstra(n,1);
        printf("%.9f\n",dist[n]);
//        for(int i=1;i<=n;i++)
//            printf("%d: %.9f\n",i,dist[i]);
 
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f
typedef pair<int, int>P;

struct edge{int to,cost;};

vector<edge> G[1007];
int d[1007];
int n,m;
int stpos,endpos;
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d,d+n,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {

        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0;i<G[v].size();i++)
        {
            edge e = G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to] = d[v]+e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
    if(d[endpos]==INF)
        printf("-1\n");
    else
        printf("%d\n",d[endpos]);
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<1007;i++) G[i].clear();
        memset(d,0,sizeof(d));
        int pos=0;
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            edge e;
            scanf("%d%d%d",&a,&b,&c);
            e.to = b;
            e.cost = c;
            G[a].push_back(e);
            e.to = a;
            e.cost = c;
            G[b].push_back(e);
        }

        scanf("%d%d",&stpos,&endpos);
        dijkstra(stpos);
    }

    return 0;
}
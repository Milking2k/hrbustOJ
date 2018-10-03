#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int maxn=1e4+7;
const int maxm=3*maxn;
int cnt;
struct node
{
    int from,to,val,next;
}edge[maxm<<1];
int head[maxm];
LL dis[maxn];
int vis[maxn];
struct Node
{
    int val,id;
    bool operator <(const Node &b)const
    {
        if(val==b.val)return id<b.id;
        return val>b.val;
    }
};
void init()
{
    memset(head,-1,sizeof(head));
    cnt=1;
}
void addedge(int from,int to,int val)
{
    edge[cnt].from=from;
    edge[cnt].to=to;
    edge[cnt].val=val;
    edge[cnt].next=head[from];
    head[from]=cnt++;
}

void dijkstra(int s,int e)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    Node now;
    priority_queue<Node>q;
    while(q.size())q.pop();
    now.val=0,now.id=s;
    dis[s]=0;
    q.push(now);
    while(!q.empty()){
        Node u=q.top();
        q.pop();
        if(vis[u.id])continue;
        vis[u.id]=1;
        for(int i=head[u.id];i!=-1;i=edge[i].next){
            int to=edge[i].to;
            if(dis[u.id]+edge[i].val<dis[to]){
                dis[to]=dis[u.id]+edge[i].val;
                Node pus;
                pus.id=to,pus.val=dis[to];
                q.push(pus);
            }
        }
    }
    return ;
}

int a[20],b[20];
LL d[20][maxn];
LL f[20][maxn];
const int qqqq=262155;
LL dp[qqqq][20];
LL minn[qqqq];
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)){
        init();
        for(int i=1;i<=m;i++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
            addedge(v,u,c);
        }
        for(int i=1;i<=k;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=1;i<=k;i++){
            dijkstra(a[i],b[i]);
            for(int j=1;j<=n;j++){
                d[i][j]=dis[j];
                if(a[i]==j)d[i][j]=0;
            }
        }
        for(int i=1;i<=k;i++){
            dijkstra(b[i],a[i]);
            for(int j=1;j<=n;j++){
                f[i][j]=dis[j];
                if(b[i]==j)f[i][j]=0;
            }
        }
        memset(dp,0x7f,sizeof(dp));
        memset(minn,0x7f,sizeof(minn));
        for(int i=0;i<k;i++){
            dp[(1<<i)][i+1]=d[i+1][b[i+1]];
        }
        int len=(1<<k)-1;
        for(int i=2;i<=len;i++){
            for(int j=0;j<k;j++){
                if(i&(1<<j)){
                    int as=i^(1<<j);
                    for(int p=0;p<k;p++){
                        if(p==j)continue;
                        if(as&(1<<p))dp[i][j+1]=min(dp[i][j+1],dp[as][p+1]+f[p+1][a[j+1]]+d[j+1][b[j+1]]);
                        minn[i]=min(minn[i],dp[i][j+1]);
                    }
                }
            }
        }
        printf("%lld\n",minn[len]);
    }
    return 0;
}

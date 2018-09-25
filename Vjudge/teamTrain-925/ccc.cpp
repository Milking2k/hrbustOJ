#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int N = 2e3+7;
int T,n,m,k,f;
int deg[N];
ll sum=0;
bool vis[N];

int head[N],ver[N*N],nxt[N*N],tot=0;
void add_edge(int u,int v){
    ver[++tot] = v,nxt[tot] = head[u],head[u] = tot;
    deg[u]++;
}
void topsort()
{
    queue<int>q;
    rep(i,1,n+1){
        if(deg[i]<k){
            q.push(i);
            sum--;
            vis[i]=1;
        }
    }
    if(sum==0) return;
    while(!q.empty()){
        int now = q.front();q.pop();
        for(int i = head[now];i;i=nxt[i]){
//            puts("tss");
            int v = ver[i];
            if(vis[v])continue;
            deg[v]--;
            if(deg[v]<k){
                q.push(v);
                vis[v] = 1;
                sum--;
                if(sum==0)return;
            }
        }
    }
}
int main()
{
    for(scanf("%d",&T);T;T--){
        tot=0;
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        memset(head,0,sizeof(head));
        scanf("%d%d%d",&n,&k,&f);
        sum=n;

        rep(i,1,f+1){
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
            add_edge(v,u);
        }
//        rep(i,1,n+1){
//            printf("%d ",deg[i]);
//        }
//        puts("");
        topsort();
        printf("%lld\n",sum);
    }

    return 0;
}


//ZOJ 3316
#include <bits/stdc++.h>
//#define re register
using namespace std;
const int N=1001;
// int t;
struct edge{
    int Next,to;
} e[N*N];
int fa[N],mark[N],match[N],vis[N],Next[N],n,m,M,g[N],x[N],y[N],L;
queue<int> q;
inline void addedge(int x,int y){
    // e[++M]=(edge){g[x]y};
    edge cnt;
    cnt.Next = g[x];
    cnt.to = y;
    e[++M] = cnt;
    g[x] = M;
}
inline void adde(int x,int y){
    addedge(x,y);addedge(y,x);
}
inline int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}
inline int unite(int x,int y){
    fa[Find(x)]=Find(y);
}
 int lca(int x,int y){
    static int t=0;
    t++;
    for(;;){
        if(x){
            x=Find(x);
            if(vis[x]==t) return x;
            vis[x]=t;
            if(match[x]) x=Next[match[x]];
            else x=0;
        }
        swap(x,y);
    }
}
inline void flower(int a,int p){
    for(;a!=p;){
        int b=match[a],c=Next[b];
        if(Find(c)!=p) Next[c]=b;
        if(mark[b]==2) q.push(b);mark[b]=1;
        if(mark[c]==2) q.push(c),mark[c]=1;
        unite(a,b);unite(b,c);
        a=c;
    }
}
inline void work(int S){
    for(int i=1;i<=n;i++)
        Next[i]=mark[i]=vis[i]=0,fa[i]=i;
    while(!q.empty()) q.pop();
    mark[S]=1;q.push(S);
    while(!q.empty()){
        if(match[S]) return;
        int x=q.front();q.pop();
        for(int i=g[x],y;i;i=e[i].Next){
            y=e[i].to;
            if(match[x]==y) continue;
            if(Find(x)==Find(y)) continue;
            if(mark[y]==2) continue;
            if(mark[y]==1){
                int r=lca(x,y);
                if(Find(x)!=r) Next[x]=y;
                if(Find(y)!=r) Next[y]=x;
                flower(x,r);flower(y,r);
            }
            else if(!match[y]){
                Next[y]=x;
                for(int u=y,v,w;u;){
                    v=Next[u];
                    w=match[v];
                    match[v]=u;match[u]=v;u=w;
                }
                break;
            }
            else{
                Next[y]=x;
                mark[match[y]]=1;
                q.push(match[y]);
                mark[y]=2;
            }
        }
    }
}

int main(){
    while(scanf("%d",&n)!=EOF){
        memset(match,false,sizeof(match));
        memset(g,false,sizeof(g));M=0;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        scanf("%d",&L);
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(abs(x[i]-x[j])+abs(y[i]-y[j])<=L){
                    adde(i,j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(!match[i]) work(i);
        }
        bool ok=true;
        for(int i=1;i<=n;i++){
            if(!match[i]){
                ok=false;
                break;
            }
        }
        if(!ok)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}


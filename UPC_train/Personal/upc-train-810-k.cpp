#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 998244353;
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=3*1e5+10;
const int M=60;
int n, m, ver[2*N], Next[2*N], head[N], tot, f[N][22], book[N];
ll dep[N];
ll dist[N][M];
ll mi[M];
inline void add(int u,int V){
    ver[++tot]=V;Next[tot]=head[u];head[u]=tot;
}
//void bfs(){
//    q.push(1);
//    d[1] = 1;
//    while(q.size()){
//        int x = q.front();
//        q.pop();
//        for(int i = head[x];i;i=Next[i]){
//            int y = ver[i];
//            if(d[y]) continue;
//            d[y] = d[x] + 1;
//            dist2[y] = dist2[x] + edge[i];
//            rep(k,1,51)
//                dist[y][k] = (dist[x][k] + powmod(dist2[y], k))%mod;
////            printf("k:%d %d_%d eg:%d  dist:%lld\n",k,x,y,edge[i],dist[y][k]);
//
//            f[y][0] = x;
//            rep(j,1,t+1) f[y][j] = f[f[y][j-1]][j-1];
//            q.push(y);
//        }
//    }
//}
inline void dfs(int u)
{
    book[u]=true;
    for(int i=0;f[u][i];i++){
        f[u][i+1]=f[f[u][i]][i];
    }
    for(int i=head[u];i;i=Next[i])
    {
        if(book[ver[i]])continue;
        f[ver[i]][0]=u;
        dep[ver[i]]=dep[u]+1;

        for(int j=1;j<=50;j++){
            mi[j]=mi[j-1]*dep[ver[i]]%mod;
        }
        for(int j=1;j<=50;j++){
            dist[ver[i]][j]=(mi[j]+dist[u][j])%mod;
            }
        dfs(ver[i]);
    }
}
//int lca(int x, int y)
//{
//    if(d[x] > d[y]) swap(x,y);
//    per(i,0,t+1) if(d[f[y][i]] >= d[x]){
//        y = f[y][i];
//    }
//    if(x==y) return x;
//    per(i,0,t+1)if(f[x][i]!=f[y][i]){
//        x = f[x][i];
//        y = f[y][i];
//    }
//
//    return f[x][0];
//}

inline int lca(int u,int v)
{
    if(dep[u]<dep[v]) swap(u,v);
    int d=dep[u]-dep[v];
    for(int i=0;d;d>>=1,i++){
            if(d&1)u=f[u][i];
    }
    if(u==v)return u;
    for(int i=20;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            u=f[u][i];v=f[v][i];
        }
    }
    return f[u][0];
}

int main()
{

//        scanf("%d",&n);
        n = read();
        mi[0] = 1;
//        rep(i,1,n+1) head[i] = 0;
        rep(i,1,n){
            int x,y,z;
//            scanf("%d%d",&x,&y);
            x = read(),y = read();
            add(x,y),add(y,x);

        }
//        bfs();
        dfs(1);

//        scanf("%d",&m);
        m = read();
        rep(i,1,m+1){
            int x,y,k;
//            scanf("%d%d%d",&x,&y,&k);
            x = read(),y = read(),k = read();
            int cnt = lca(x,y);
            printf("%lld\n",(dist[x][k] + dist[y][k]- dist[cnt][k] - dist[f[cnt][0]][k] + 2*mod)%mod);
        }
    return 0;
}



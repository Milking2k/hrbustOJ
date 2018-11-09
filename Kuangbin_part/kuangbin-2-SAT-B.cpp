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
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e6+7;
const int M = 1e6+7;
int T,n,m;

/*2sat*/
int i;
int q[N],t,f[N];bool vis[N];
struct E{int v;E*nxt;}*g[N],*h[N],pool[N*4],*cur;

inline void addedge(int x, int y){
    E *p = cur++;p->v = y;p->nxt = g[x];g[x] = p;
       p = cur++;p->v = x;p->nxt = h[y];h[y] = p;
}
void dfs1(int x)
{
    vis[x] = 1;
    for (E *p = g[x]; p; p = p->nxt) if (!vis[p->v]) dfs1(p->v);
    q[++t] = x;
}
void dfs2(int x,int y){
    vis[x]=0,f[x]=y;
    for(E*p=h[x];p;p=p->nxt)if(vis[p->v])dfs2(p->v,y);
}
void Twosat()
{

    int o = 0;
    for (t = 0, i = 1; i <= n + n; i++)
        if (!vis[i])
            dfs1(i);
    for (i = t; i; i--)
        if (vis[q[i]])
            dfs2(q[i], ++o);
    for (i = 1; i <= n; i++)
        if (f[i] == f[i + n])
        {
            printf("no\n");
            return;
        }

    printf("yes\n");
    // for(i=1;i<=n;i++)printf("%d\n",f[i]<f[i+n]?i+n:i);
}
int id[N];
int main()
{
    int n, m;
    int u, v;
    while (scanf("%d%d", &n, &m) == 2)
    {
        for(cur=pool,i=0;i<=n+n;i++)g[i]=h[i]=NULL,vis[i]=0;
        int a, b, c, d;
        // init();
        rep(i,0,n){
            scanf("%d%d%d", &a, &b, &c);
            id[a] = i * 2;
            id[b] = id[c] = i * 2 + 1;
        }
        rep(i,1,m+1){
            scanf("%d%d", &a, &b);
            addedge(id[a], id[b] ^ 1);
            addedge(id[b], id[a] ^ 1);
        }
        Twosat();
    }
    return 0;
}
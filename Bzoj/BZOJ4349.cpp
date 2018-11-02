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
typedef pair<double,int> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 57, M = 50050, inf = 0x7fffffff;
PII a[N];
ll tot = 0;
int n, m, ROOT,st;
struct DMST
{
    typedef double type;
    int n, size, pre[N], id[N], vis[N];
    type in[N];
    struct EDGE
    {
        int u, v;
        type cost;
        EDGE() {}
        EDGE(int a, int b, double c) : u(a), v(b), cost(c) {}
    } E[M];
    void init(int _n) { n = _n, size = 0; }
    void add(int u, int v, type w) { E[size++] = EDGE(u, v, w); }
    type dmst(int root){
        int u, v;
        type ret = 0;
        while (1)
        {
            for (int i = 0; i < n; i++)
                in[i] = inf;
            for (int i = 0; i < size; i++)
            {
                u = E[i].u, v = E[i].v;
                if (E[i].cost < in[v] && u != v)
                {
                    pre[v] = u, in[v] = E[i].cost;
                    if (u == root)
                        ROOT = i;
                }
            }
            for (int i = 0; i < n; i++)
                if (i != root && in[i] == inf)
                    return -1;
            int cnt = 0;
            in[root] = 0;
            for (int i = 0; i < n; i++)
                id[i] = vis[i] =-1;
            for (int i = 0; i < n; i++)
            {
                ret += in[i], v = i;
                while (vis[v] != i && id[v] ==-1 && v != root)
                    vis[v] = i, v = pre[v];
                if (v != root && id[v] ==-1)
                {
                    for (u = pre[v]; u != v; u = pre[u])
                        id[u] = cnt;
                    id[v] = cnt++;
                }
            }


            if (cnt==0)
                break;
            for (int i = 0; i < n; i++)
                if (id[i] ==-1)
                    id[i] = cnt++;
            for (int i = 0;  v = E[i].v, i < size; i++)
            {
                E[i].u = id[E[i].u], E[i].v = id[E[i].v];
                if (E[i].u != E[i].v)
                    E[i].cost-= in[v];
            }

            n = cnt, root = id[root];
        }
        return ret;
    }
}G;

double variable(int &root)
{
    for (int i = 0; i < n; i++)
        G.add(st, i, a[i].fi); //st=n,tot=sum of Edge Wight+1
    return G.dmst(n);
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    G.init(n+1);
    st = n;

    rep(i, 0, n) cin >> a[i].fi >> a[i].se;
    cin >> m;
    rep(i,0,m){
        int u, v;
        double w;
        cin >> u >> v >> w;
        u--, v--;
        G.add(u, v, w);
        a[v].fi = min(a[v].fi, w);
    }

    int root;
    double cost = variable(root);

    rep(i,0,n){
        cost += (a[i].se - 1) * a[i].fi;
    }
    printf("%.2f\n", cost);
    return 0;
}

/*

3
10.00 1
1.80 1
2.50 2
2
1 3 2.00
3 2 1.50


:::3 ::0.00 2.00
3 2 1.50
:::2 ::1.50 1.50
14.80



*/
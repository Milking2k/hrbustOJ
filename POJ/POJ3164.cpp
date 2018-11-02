// #include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
// #define per(i,a,n) for (int i = n-1; i>=a; i--)
// #define pb push_back
// #define mp make_pair
// #define all(now) (now).begin(),(now).end()
#define fi first
#define se second
// #define SZ(now) ((int)(now).size())
// typedef vector<int> VI;
// typedef long long ll;
typedef pair<double, double> PII;
// const ll mod = 1000000007;
// inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
// ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
// ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e2 + 7;
// const int M = 1e4 + 7;
int T, n, m;

typedef double type;
struct node
{
    int u, v;
    type w;
} edge[N * N];
int pre[N], id[N], vis[N], pos;
type in[N];
const int INF = 0x3f3f3f3f;
type Directed_MST1(int root, int V, int E)
{
    type ret = 0; //最小树形图的总权值
    while (1)
    {
        // 1 找到节点最小的边
        rep(i, 0, V) in[i] = INF;
        rep(i, 0, E)
        {
            int u = edge[i].u;
            int v = edge[i].v;

            // 当顶点V有权值较小的入边，记录到E0中
            if (edge[i].w < in[v] && u != v)
            {
                pre[v] = u;
                in[v] = edge[i].w;
            }
        }

        rep(i, 0, V)
        {
            // 除了根以外，还有点没入边，这个点无法到达根，无法构成树形图
            if (in[i] == INF && i != root)
                return -1;
        }

        // 2. 找环
        int cnt = 0; // 记录着环数
        in[root] = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        rep(i, 0, V)
        {
            ret += in[i];

            int v = i;
            while (vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v]; // 回溯判根
            }

            if (id[v] == -1 && v != root)
            {
                for (int u = pre[v]; u != v; u = pre[u])
                {
                    id[u] = cnt;
                }
                id[v] = cnt++;
            }
        }

        if (cnt == 0)
            break; //无环

        rep(i, 0, V) if (id[i] == -1)
        {
            id[i] = cnt++;
        }

        // 3. 建立新的图，缩点，重新标记
        rep(i, 0, E)
        {
            int u = edge[i].u;
            int v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if (id[u] != id[v])
            {
                edge[i].w -= in[v];
            }
        }
        V = cnt;
        root = id[root];
    }
    return ret;
}

// double Directed_MST(int root, int n, int m)
// {
//     int i, j, k;
//     int u, v, cnt;
//     double ans = 0;
//     while (1)
//     {
//         for (i = 1; i <= n; i++)
//             id[i] = vis[i] = 0, in[i] = INF;
//         for (i = 1; i <= m; i++)
//         {
//             u = edge[i].u;
//             v = edge[i].v;
//             if (in[v] > edge[i].w)
//                 pre[v] = u, in[v] = edge[i].w;
//         }
//         for (i = 1; i <= n; i++)
//             if (in[i] == INF && i != root)
//                 return -1;
//         in[root] = cnt = 0;

//         for (i = 1; i <= n; i++)
//         {
//             ans += in[i];
//             if (vis[i])
//                 continue;
//             for (v = i; !vis[v] && v != root; vis[v] = i, v = pre[v])
//                 ;
//             if (v != root && vis[v] == i)
//             {
//                 id[v] = ++cnt;
//                 for (u = pre[v]; u != v; u = pre[u])
//                     id[u] = cnt;
//             }
//         }
//         if (!cnt)
//             break;
//         for (i = 1; i <= n; i++)
//             if (!id[i])
//                 id[i] = ++cnt;
//         n = cnt, cnt = 0, root = id[root];
//         for (i = 1; i <= m; i++)
//         {
//             u = edge[i].u, v = edge[i].v;
//             if (id[u] != id[v])
//             {
//                 edge[++cnt].u = id[u];
//                 edge[cnt].v = id[v];
//                 edge[cnt].w = edge[i].w - in[v];
//             }
//         }
//         m = cnt;
//     }
//     return ans;
// }

double dis(PII a, PII b)
{
    return sqrt(1.0 * (a.fi - b.fi) * (a.fi - b.fi) + 1.0 * (a.se - b.se) * (a.se - b.se));
}

PII a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    double ans = 0;
    while (cin >> n >> m)
    {
        rep(i, 1, n + 1) cin >> a[i].fi >> a[i].se;
        rep(i, 1, m + 1)
        {
            scanf("%d%d", &edge[i].u, &edge[i].v);
            if (edge[i].u != edge[i].v)
                edge[i].w = dis(a[edge[i].u], a[edge[i].v]);
            else
                i--, m--;
        }
        ans = Directed_MST1(1, n, m);
        if (ans == -1)
            printf("poor snoopy\n");
        else
            printf("%.2f\n", ans);
    }
    return 0;
}

/*
const int N = 10050, M = 50050, inf = 0x7fffffff;
int n, m, ROOT;
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
        EDGE(int a, int b, type c) : u(a), v(b), cost(c) {}
    } E[M];
    void init(int _n) { n = _n, size = 0; }
    void add(int u, int v, int w) { E[size++] = EDGE(u, v, w); }
    int dmst(int root)
    {
        int u, v, cnt;
        double ret = 0;
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
            cnt = in[root] = 0;
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
            if (!cnt)
                break;
            for (int i = 0; i < n; i++)
                if (id[i] ==-1)
                    id[i] = cnt++;
            for (int i = 0; v = E[i].v, i < size; i++)
            {
                E[i].u = id[E[i].u], E[i].v = id[E[i].v];
                if (E[i].u != E[i].v)
                    E[i].cost-= in[v];
            }

            n = cnt, root = id[root];
        }
        return ret;
    }
};*/

// void variable(int &cost, int &root)
// { //Variable Root
//     for (int i = 0; i < n; i++)
//         G.add(st, i, tot); //st=n,tot=sum of Edge Wight+1
//     int ans = G.dmst(st);
//     if (ans ==-1 || ans-tot > tot)
//         return; //No solution
//     cost = ans-tot, root = ROOT-m;
// }


// int dis(PII a, PII b)
// {
//     return sqrt(1.0*(a.fi - b.fi) * (a.fi - b.fi) + 1.0*(a.se - b.se) * (a.se - b.se));
// }

// PII a[N];
// int main()
// {
//     //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     double ans = 0;
//     while (cin >> n >> m)
//     {
//         DMST dmst;
//         dmst.init(n);
//         rep(i, 1, n + 1) cin >> a[i].fi >> a[i].se;
//         rep(i, 1, m + 1)
//         {
//             int u, v;
//             double w;
//             scanf("%d%d", &u, &v);
//             if (u != v)
//                 w = dis(a[u], a[v]);
//             else
//                 i--, m--;
//             dmst.add(u, v, w);
//         }
//         ans = dmst.dmst(1);
//         if (ans == -1)
//             printf("poor snoopy\n");
//         else
//             printf("%.2f\n", ans);
//     }
//     return 0;
// }
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define rep(i, a, n) for (int i = a; i < n; i++)
#define fi first
#define se second
typedef pair<double, double> PII;
// head
const int N = 1050, M = 50050, inf = 0x7fffffff;
int n, m, ROOT;
    typedef double type;
struct DMST
{
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
    type dmst(int root)
    {
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
};

void variable(int &cost, int &root)
{ //Variable Root
    for (int i = 0; i < n; i++)
        G.add(st, i, tot); //st=n,tot=sum of Edge Wight+1
    int ans = G.dmst(st);
    if (ans ==-1 || ans-tot > tot)
        return; //No solution
    cost = ans-tot, root = ROOT-m;
}


double dis(PII a, PII b)
{
    return sqrt(1.0*(a.fi - b.fi) * (a.fi - b.fi) + 1.0*(a.se - b.se) * (a.se - b.se));
}

PII a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    double ans = 0;
    while (cin >> n >> m)
    {
        DMST dmst;
        dmst.init(n);
        rep(i, 0, n) cin >> a[i].fi >> a[i].se;
        rep(i, 0, m)
        {
            int u, v;
            double w;
            scanf("%d%d", &u, &v);
            u--, v--;
            if (u != v)
                w = dis(a[u], a[v]);
            else
                w = inf;
            dmst.add(u, v, w);
        }
        double ans = dmst.dmst(0);
        if (ans == -1)
            printf("poor snoopy\n");
        else
            printf("%.2f\n", ans);
    }
    return 0;
}
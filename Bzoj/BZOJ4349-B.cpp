#include<cstdio>
#include<algorithm>
#define N 55
#define K 23333
using namespace std;

typedef double db;
const double INF = 1e9;
const int M = 300;
const double inf = 1e9;
struct pdge{int from, to; db val;}pe[K];
int pecnt, n, k, b[N], S, pre[N], vis[N], bel[N], ban[N];
db a[N], ans, in[N];
// db DMST()
// {
//     db r = 0;
//     for(;;)
//     {
//         for(int i = 1; i <= n; i++) in[i] = INF, pre[i] = vis[i] = bel[i] = 0;
//         for(int i = 1; i <= pecnt; i++)
//         {
//             int from = pe[i].from, to = pe[i].to;
//             if(from != to && pe[i].val < in[to])
//                 in[to] = pe[i].val, pre[to] = from;
//         }
//         int findring = 0;
//         for(int i = 1, j; i <= n; i++) if(!ban[i])
//         {
//             r += in[i];
//             for(j = i; !vis[j] && j; j = pre[j]) vis[j] = i;
//             if(vis[j] == i)
//             {
//                 for(int k = pre[j]; k != j; k = pre[k]) bel[k] = j;
//                 bel[j] = j; findring = 1;
//             }
//             if(!bel[i]) bel[i] = i;
//         }
//         for(int i = 1; i <= n; i++) if(!ban[i] && bel[i] != i) ban[i] = 1;
//         if(!findring) return r;
//         for(int i = 1; i <= pecnt; i++)
//         {
//             int &from = pe[i].from, &to = pe[i].to; db &val = pe[i].val;
//             if(from != to)
//             {
//                 val -= in[to];
//                 from = bel[from];
//                 to = bel[to];
//             }
//         }
//     }
//     return -233;
// }


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
                    // if (u == root)
                    //     ROOT = i;
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

int main()
{
    scanf("%d",&n); S = n + 1;
    G.init(S);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lf%d",&a[i],&b[i]);
        // pe[++pecnt] = (pdge){S, i, a[i]};
        G.add(S, i, a[i]);
    }
    scanf("%d",&k);
    for(int i = 1; i <= k; i++)
    {
        int x, y; db z;
        scanf("%d%d%lf",&x,&y,&z);
        // pe[++pecnt] = (pdge){x, y, z};
        G.add(x, y, z);
        a[y] = min(a[y], z);
    }
    // ans += DMST();
    ans += G.dmst(S);
    for(int i = 1; i <= n; i++)
        ans += (b[i] - 1) * a[i];
    printf("%.2lf\n",ans);
}

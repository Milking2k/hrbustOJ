// #include <bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<assert.h>
#include<queue>
#include<algorithm>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

#define inf 0x3f3f3f3f
#define Max 1005
int dist[Max];
int g[Max][Max];
int used[Max];
int n, m, i;
void add_edge(int a, int b, int c)
{
    if (g[a][b] > c)
    {
        g[a][b] = g[b][a] = c;
    }
}
void init()
{
    memset(used, 0, sizeof(used));
    memset(dist, inf, sizeof(dist));
}
void Dijkstra(int begin)
{
    init();
    dist[begin] = 0;
    while (1)
    {
        int min = inf, u = -1, v;
        for (i = 1; i <= n; i++)
        {
            if (min > dist[i] && !used[i])
            {
                min = dist[i];
                u = i;
            }
        }
        used[u] = 1;
        if (u == -1)
        {
            break;
        }
        for (v = 1; v <= n; v++)
        {
            if (!used[v] && dist[v] > dist[u] + g[u][v])
            {
                dist[v] = dist[u] + g[u][v];
            }
        }
    }
}
int main()
{
    while (scanf("%d%d", &m, &n) != EOF)
    {
        int a, b, c;
        memset(g, inf, sizeof(g));
        for (i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
        }
        Dijkstra(1);
        printf("%d\n", dist[n]);
    }
    return 0;
}
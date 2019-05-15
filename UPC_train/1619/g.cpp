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

const int MAXN = 20010;
const int MAXM = 50010;
struct Edge
{
    int to, next;
} edge[MAXM];
int head[MAXN], tot;
int low[MAXN], dfn[MAXN], stk[MAXN], belong[MAXN];
int Index, top;
int scc; //强连通分量的个数
bool Instack[MAXN];
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void Tarjan(int u)
{
    int v;
    low[u] = dfn[u] = ++Index;
    stk[top++] = u;
    Instack[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if (!dfn[v])
        {
            Tarjan(v);
            if (low[u] > low[v])
                low[u] = low[v];
        }
        else if (Instack[v] && low[u] > dfn[v])
            low[u] = dfn[v];
    }
    if (low[u] == dfn[u])
    {
        scc++;
        do
        {
            v = stk[--top];
            Instack[v] = false;
            belong[v] = scc;
            // num[scc]++;
        } while (v != u);
    }
}
void solve(int N)
{
    memset(dfn, 0, sizeof(dfn));
    memset(Instack, false, sizeof(Instack));
    // memset(num, 0, sizeof(num));
    Index = scc = top = 0;
    for (int i = 1; i <= N; i++)
        if (!dfn[i])
            Tarjan(i);
}
void init()
{
    tot = 0;
    memset(head,-1, sizeof(head));
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T, n, m;
    scanf("%d", &T);
    while(T--){
        init();
        scanf("%d%d", &m,&n);
        rep(i,1,n+1){
            int x, y;
            scanf("%d%d", &x, &y);
            x++, y++;
            addedge(x, y);
        }
        solve(m);
        printf("%d\n", scc);
    }
    return 0;
}

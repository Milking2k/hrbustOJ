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
const int N = 100+7;
const int M = 1e4 + 7;
int T,n,m;

int head[N], ver[M], Next[M], edge[M], tot, tot2;
void addedge(int u, int v, int w)
{
    edge[++tot] = w, ver[tot] = v, Next[tot] = head[u], head[u] = tot;
}

PII edge_v[N];
int vis[N], vis2[N];
int max_len, root, cntRoot;
int getDlenCent(int x, int len)
{
    vis[x]=1;
    if(len > max_len) max_len=len, root=x;
    if(len == max_len / 2) cntRoot = x;
    for (int i = head[x]; i; i = Next[i]) {
        if(!vis[ver[i]]) {
            getDlenCent(ver[i], len + 1);
        }
    }
    return max_len;
}

int solve1(int root, int flag)
{
    int res = 0;
    queue<int> Q;
    Q.push(root);
    vis2[root] = 1;
    while (Q.size())
    {
        int cur = Q.front();Q.pop();
        for (int i = head[cur]; i; i = Next[i]) {
            int y = ver[i];
            if (vis[y] || edge[i] * flag < 0)
                continue;
            vis[y] = 1;
            vis2[y] = 1;
            res++;
            Q.push(y);
        }
    }
    return res;
}

int tpin[N];
bool topsort()
{
    queue<int> Q;
    while(Q.size()) Q.pop();
    int res = 0;
    rep(i, 1, n + 1) if (tpin[i] == 0) Q.push(i);
    while (!Q.empty())
    {
        res++;
        int cur = Q.front();Q.pop();
        for (int i = head[cur]; i; i = Next[i]) {
            if(edge[i] < 0) continue;
            int y = ver[i];
            tpin[y]--;
            if(tpin[y] <= 0) Q.push(y);
        }
    }
    // printf("res:%d\n", res);
    return (res == n);
}

bool hasCircle(int u)
{
    if(vis[u]==2) return true;
    vis[u] = 2;
    for (int i = head[u]; i; i = Next[i]) {
        int v = ver[i];
        if(edge[i] < 0) continue;
        if(vis[v]==0)
        {
            if(hasCircle(v)) return true;
        }
        else if(vis[v]==2) return true;
    }
    vis[u] = 1;
    return false;
}

int ptans[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        memset(head, 0, sizeof(head));
        memset(tpin, 0, sizeof(tpin));
        fill(vis, vis + n + 5, 0);
        fill(vis2, vis2 + n + 5, 0);
        tot = 0;
        tot2 = 0;
        max_len = 0;
        scanf("%d%d", &n, &m);
        rep(i,1,m+1) {
            int u, v;
            scanf("%d%d", &u, &v);
            // edge_v[i] = {u, v};
            tpin[v]++;
            addedge(u, v, 1);
            addedge(v, u, -1);
        }

        bool ok = 0;
        fill(vis, vis + n + 5, 0);
        // rep(i, 1, n + 1) if (!vis[i]) {
        //     if(hasCircle(i)){
        //         ok = 1;
        //         break;
        //     }
        // }
        if (!topsort())
        {
            rep(i, 1, n + 1) printf("0");
            printf("\n");
            continue;
        }
        // getDlenCent(1, 0);
        // fill(vis,vis+n+5,0);
        // getDlenCent(root, 0);
        // getDlenCent(root, 0); // get center

        int resans = 0;
        memset(ptans, 0, sizeof(ptans));
        rep(cntRoot, 1, n+1){
            fill(vis2, vis2 + n + 5, 0);
            fill(vis, vis + n + 5, 0);
            int res1 = solve1(cntRoot, 1);
            fill(vis,vis+n+5,0);
            int res2 = solve1(cntRoot, -1);

            int temp = 0;
            rep(i,1,n+1) {
                if(vis2[i] == 0)
                    temp++;
                // if (vis2[edge_v[i].fi] == 0 || vis2[edge_v[i].se] == 0)
                //     temp++;
            }

            // printf("temp:%d res1:%d res2:%d\n",temp, res1, res2);
            resans = temp - abs(res1 - res2);
            if(resans < 0) continue;
            ptans[cntRoot] = 1;
        }
        rep(i, 1, n + 1) printf("%d",ptans[i]);
        printf("\n");

    }
    return 0;
}
/*

*/
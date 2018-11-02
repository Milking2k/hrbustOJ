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
const int N = 1e3+7;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
int T,n,m;

struct node
{
    int u,v;
    ll w;
} edge[N * N];
int pre[N],id[N],vis[N],pos;
ll in[N];

ll Directed_MST(int root, int V, int E)
{
    ll ret = 0;//最小树形图的总权值
    while(1){
        // 1 找到节点最小的边
        rep(i, 0, V) in[i] = INF;
        rep(i, 0, E) {
            int u = edge[i].u;
            int v = edge[i].v;

            // 当顶点V有权值较小的入边，记录到E0中
            if(edge[i].w < in[v] && u!=v){
                pre[v] = u;
                in[v] = edge[i].w;

                // 如果这个点为实际的起点
                if(u==root){
                    pos = i;
                }
            }
        }

        rep(i,0,V){
            if(i==root) continue;

            // 除了根以外，还有点没入边，这个点无法到达根，无法构成树形图
            if(in[i]==INF) return -1;
        }

        // 2. 找环
        int cnt = 0; // 记录着环数
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        rep(i,0,V){
            ret += in[i];
            
            int v = i;
            while(vis[v] !=i && id[v] ==-1 && v!=root){
                vis[v] = i;
                v = pre[v]; // 回溯判根
            }

            if(id[v] == -1 && v!=root){
                for (int u = pre[v]; u != v; u = pre[u]){
                    id[u] = cnt;
                }
                id[v] = cnt++;
            }
        }

        if(cnt==0) break;//无环

        rep(i, 0, V) if (id[i] == -1) {
            id[i] = cnt++;
        }

        // 3. 建立新的图，缩点，重新标记
        rep(i,0,E) {
            int u = edge[i].u;
            int v = edge[i].v;
            edge[i].u = id[u];
            edge[i].v = id[v];
            if (id[u] != id[v]) {
                edge[i].w -= in[v];
            }
        }
        V = cnt;
        root = id[root];
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while (cin >> n >> m){
        ll sum = 0;
        rep(i,0,m){
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
            edge[i].u++, edge[i].v++;
            sum += edge[i].w;
        }
        sum++; // 建立虚拟根，起连接其他所有点并且比安全为=1 + ∑边;

        rep(i,m,m+n){
            edge[i].u = 0;
            edge[i].v = i - m + 1;
            edge[i].w = sum;
        }

        ll ans = Directed_MST(0, n + 1, m + n);

        if (ans == -1 || ans - sum >= sum) {
            cout << "impossible" << "\n";
        }
        else{
            cout << ans - sum << " " << pos - m << "\n";
        }
        cout << "\n";
    }
        return 0;
}
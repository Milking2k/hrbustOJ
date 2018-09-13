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
const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
struct edge
{
    int to, w;
};
int T,n,m,r;
int dist[N], dist2[N];
vector<edge> G[N];
void solve()
{
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    fill(dist, dist + n, INF);
    fill(dist, dist + n, INF);
    dist[0] = 0;
    Q.push(PII(0, 0));
    while(!Q.empty()){
        PII p = Q.top();
        Q.pop();
        int v = p.se, d = p.fi;
        if(dist2[v] < d) continue;

        rep(i,0,G[v].size()){
            edge &e = G[v][i];
            int d2 = d + e.w;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                Q.push(PII(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[e.to] < d2){
                dist2[e.to] = d2;
                Q.push(PII(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[n - 1]);
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(~scanf("%d%d",&n,&r)){
        rep(i,1,r+1){
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            edge cnt = {v, w};
            G[u].pb(cnt);
            cnt = {u, w};
            G[v].pb(cnt);
        }
        solve();
    }
    return 0;
}
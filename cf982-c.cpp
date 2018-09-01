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
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e5+7;
int T,n,m,k,l,ans=0;
int sz[N];
vector<int>edge[N];

void dfs(int u, int p)
{
    sz[u] = 1;
    rep(i,0,edge[u].size()){
        int v = edge[u][i];
        if(v != p){
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
    if(sz[u]%2==0) ans++;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n;
    rep(i,1,n){
        int u,v;
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    if(n%2==1)cout << "-1\n";
    else dfs(1,0),cout << ans - 1 << "\n";
    return 0;
}

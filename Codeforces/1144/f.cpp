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
const int N = 2e5+7;
int T,n,m;
vector<PII> e;
VI g[N];
VI color;
bool ans;

void dfs(int v, int c) {
    color[v] = c;
    for (auto to : g[v]) {
        if(color[to] == -1) {
            dfs(to, c ^ 1);
        } else if(color[to] == color[v])
            ans = false;
    }
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i,0,m) {
        int x,y;
        cin >> x >> y;
        --x,--y;
        g[x].pb(y);
        g[y].pb(x);
        e.pb(mp(x, y));
    }
    ans = true;
    color = vector<int>(n, -1);
    dfs(0, 0);
    if(!ans) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES\n";
    rep(i,0,m) {
        cout << (color[e[i].first] < color[e[i].second]);
    }

    return 0;
}
/*

*/
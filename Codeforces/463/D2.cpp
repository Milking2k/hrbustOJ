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
int T,n,m;
int a[N], f[N], pos[N];
bool flag[N][N];
vector<int> g[N];

int dfs(int x)
{
    if(f[x] != -1)
        return f[x];
    f[x] = 0;
    for (auto u:g[x]){
        f[x] = max(f[x], dfs(u));
    }
    return ++f[x];
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    memset(f, -1, sizeof(f));
    memset(flag, 1, sizeof(flag));
    cin>>n>>m;
    rep(i,1,m+1){
        rep(j,1,n+1){
            int x;
            cin >> x;
            pos[x] = j;
        }
        rep(j,1,n+1){
            rep(k,1,n+1){
                flag[j][k] &= pos[j] < pos[k];
            }
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(flag[i][j]){
                g[i].pb(j);
            }
        }
    }

    int ans = 0;
    rep(i,1,n+1){
        ans = max(ans, dfs(i));
    }
    printf("%d\n", ans);
    return 0;
}
/*

*/
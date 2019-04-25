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

const int maxn=2e5+50;
int n,m,k;
ll dp[maxn],sum[maxn];
int f[maxn], a[maxn];

ll dfs(int);

int main()
{
    int x, y;
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    rep(i, 1, n + 1) cin >> a[i];
    sort(a + 1, a + 1 + n);
    rep(i, 1, min(2000, n) + 1) sum[i] = sum[i - 1] + a[i];
    rep(i, 1, m + 1){
        cin >> x >> y;
        f[x] = max(f[x], y);
    }
    cout << dfs(k) << endl;
    return 0;
}
ll dfs(int x){
    ll ans = 1e18;
    if(x==0)
        return 0;
    if (dp[x] != -1)
        return dp[x];
    int num;
    per(i, 1, x + 1)
    {
        num = x - i + 1;
        num = f[num];
        ans = min(ans, dfs(i - 1) + sum[x] - sum[i - 1] - sum[i + num - 1] + sum[i - 1]);
    }
    return dp[x] = ans;
}
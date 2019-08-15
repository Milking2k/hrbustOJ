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
const int N = 1e6+7;
int T,n,m;

int solve(string s, string p)
{
    size_t n = s.size(), m = p.size();
    // vector<vector<int> > dp;
    // dp.resize(s.size() + 7);
    // for (size_t i = 0; i < n; ++i)
    //     dp[i].resize(p.size() + 7);
    int dp[n+7][m+7];
    memset(dp,0,sizeof(dp));
    for (size_t i = 0; i <= n; ++i) {
        dp[i][0] = i;
    }
    for (size_t i = 0; i <= m; ++i) {
        dp[0][i] = i;
    }

    for (size_t i = 1; i <= n; ++i) {
        for (size_t j = 1; j <= m; ++j) {
            dp[i][j] = min(dp[i][j-1] + 1, min(dp[i - 1][j] + 1, dp[i-1][j-1] + (s[i-1] != p[j-1])));
        }
    }
    return dp[n][m];
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s,p;
    cin >> s >> p;
    printf("%d", solve(s,p));
    return 0;
}
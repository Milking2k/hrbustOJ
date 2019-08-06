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
bool solve(string s, string p)
{
    if (p.empty()) return s.empty();

    if (p.size() == 1 || p[1] != '*') {
        if(s.empty() || (s[0] != p[0] && p[0] != '.')) 
            return false;
        else 
            return solve(s.substr(1), p.substr(1));
    }

    // p >= 2 && p[0] == '*'
    while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
        if (solve(s, p.substr(2))) {
            return true;
        }
        s = s.substr(1);
    }
    return solve(s, p.substr(2));
}

// dp function
bool solve2(string s, string p)
{
    int n = s.size(), m = p.size();
    bool dp[1007][1007];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i < m; ++i) {
        if (p[i] == '*' && dp[0][i - 1])
            dp[0][i + 1] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (s[i] == p[j] || p[j] == '.') {
                dp[i + 1][j + 1] = dp[i][j];
            }
            else if (p[j] == '*') {
                if (s[i] != p[j - 1] && p[j - 1] != '.') {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1];
                }
                else {
                    dp[i + 1][j + 1] = (dp[i + 1][j] || dp[i][j + 1] || dp[i + 1][j - 1]);
                }
            }
        }
    }
    return dp[n][m];
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s,p;
    cin >> s >> p;
    printf("%s", solve(s,p) == 1 ? "true" : "false");
    return 0;
}
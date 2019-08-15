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
        int n = s.size(), m = p.size();
        if (n != m) return false;
        if (s == p) return true;
        vector<vector<vector<bool>>> dp(n+1, vector<vector<bool>>(n+1, vector<bool> (n+1, false)));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                dp[i][j][1] = (s[i] == p[j]);
            }
        }
        for (size_t len = 2; len <= n; ++len) {
            for (size_t i = 0; i <= n - len; ++i) {
                for (size_t j = 0; j <= n - len; ++j) {
                    for (size_t k = 1; k < len; ++k) {
                        if ((dp[i][j][k] && dp[i + k][j + k][len - k]) ||
                            (dp[i + k][j][len - k] && dp[i][j + len - k][k]))
                        {
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }


        return dp[0][0][n];
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s,p;
    cin >> s >> p;
    printf("%s\n", solve(s,p)?"true":"false");
    return 0;
}
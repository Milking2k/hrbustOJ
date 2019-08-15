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
int solve(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    if(m==0) return 1;
    if(n==0) return 0;
    vector<vector<int>> dp(m+7, vector<int>(n+7, 0));
    for (int i = 0; i <= n; ++i) dp[0][i] = 1;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] += dp[i][j-1] + (s1[j - 1] == s2[i - 1])*dp[i-1][j-1];
        }
    }
    return dp[m][n];
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s1,s2;
    cin >> s1 >> s2;
    printf("%d\n", solve(s1,s2));
    return 0;
}
/*
babgbag
bag

 */
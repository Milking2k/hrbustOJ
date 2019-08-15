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
bool solve(string s1, string s2, string s3)
{
    int n = s1.size(), m = s2.size();
    if (n + m != s3.size()) return false;

    vector<vector<bool> > dp(n+7, vector<bool>(m+7, false));
    dp[0][0] = true;
    int i = 1;
    while(i <= n && s1[i-1] == s3[i-1]) dp[i++][0] = true;
    i = 1;
    while(i <= m && s2[i-1] == s3[i-1]) dp[0][i++] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((dp[i-1][j] && s1[i-1] == s3[j+i-1])
            ||(dp[i][j-1] && s2[j-1] == s3[i+j-1]))
                dp[i][j] = true;
        }
    }
    return dp[n][m];
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    printf("%s", solve(s1,s2,s3)?"true":"false");
    return 0;
}
/*
aabcc
dbbca
aadbbbaccc

 */
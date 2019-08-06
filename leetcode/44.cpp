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
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s, p;
    cin >> s;
    cin >> p;
    bool dp[1007][1007];
    int n = s.size();
    int m = p.size();
    memset(dp,0,sizeof(dp));
    
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (p[i-1] == '*') {
            dp[0][i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char x = s[i-1], y = p[j-1];
            if (x == y || y == '?' || y == '*') {
                dp[i][j] = dp[i][j] | dp[i-1][j-1];
            }
            if (y == '*') {
                dp[i][j] = dp[i][j] | dp[i][j-1] | dp[i-1][j];
            }
        }
    }
    printf("%d\n", dp[n][m]);
    return dp[n][m];


    return 0;
}
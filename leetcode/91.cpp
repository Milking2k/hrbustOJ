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
int solve(string s)
{
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;

    vector<ll> dp(n+7, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] != '0')
            dp[i] = dp[i - 1];
        if (i > 1) {
            int temp = (s[i-2] - '0')*10 + (s[i-1] - '0');
            printf("%d\n", temp);
            if (9 < temp && temp < 27) {
                dp[i] += dp[i-2];
            }
        }
    }
    return dp[n];
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    printf("%d\n", solve(s));
    return 0;
}



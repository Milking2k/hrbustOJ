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
        int n = s.length();
        vector<vector<bool>>dp (n+7, vector<bool>(n+7, 0));
        vector<int> ans(n+7, 0x3f3f3f3f);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                
                if (i == j || i + 1 == j && s[i] == s[j]) {
                    dp[i][j] = 1;
                }
                else if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j]) {
                    if (j == n - 1) {
                        ans[i] = 0;
                    }
                    else {
                        ans[i] = min(ans[i], ans[j + 1] + 1);
                    }
                }
            }
        }
        
        return ans[0];
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    printf("%d\n", solve(s));
    return 0;
}
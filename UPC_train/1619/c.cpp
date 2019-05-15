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
PII a[N];
int dp[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(~scanf("%d%d",&n,&m)){
        rep(i, 1, n + 1) scanf("%d", &a[i].fi), a[i].se = i;

        sort(a + 1, a + 1 + n);
        dp[1] = 0;
        dp[0] = 0;
        rep(i,1,n+1){
            // printf("%d:", a[i].se);
            rep(j,1,i){
                // printf("_%d_", a[j].se);
                if(a[i].se <= a[j].se + m && a[i].se >= a[j].se - m && a[i].fi > a[j].fi){
                    dp[i] = max(dp[i], dp[j]+1);
                }
                // printf("%d\n", dp[i]);
            }
        }
        int ans = 0;
        rep(i, 1, n + 1) ans = max(ans, dp[i]);

        printf("%d\n", ans);
    }
    return 0;
}
/*

*/
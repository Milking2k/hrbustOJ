#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e8+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e6+7;
int T, n, m, k;
char s[N];
int a[N];
int dp[N];
int main()
{
    for (scanf("%d", &T); T;T--){
        ll ans = 0;
        scanf("%s", s+1);
        n = strlen(s+1);
        rep(i,1,n+1) a[i] = s[i] - '0';
        rep(k,0,a[1]+1){
            dp[1] = k;
            if(k>2) break;
            int cnt;
            rep(i,2,n+1){
                cnt = a[i - 1] - dp[i - 1] - dp[i - 2];
                if(cnt<0 || cnt>2) break;
                dp[i] = cnt;
            }
            if (cnt < 0 || cnt > 2 || dp[n - 1] + dp[n] != a[n])
                continue;
            ll nans = 1;
            rep(i, 1, n+1) if (dp[i] == 1) nans = nans * 2 % mod;
            ans = (ans + nans) % mod;
        }
        printf("%lld\n", ans);
    }

        return 0;
}
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
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e6+7;
const int INF = 0x3f3f3f3f;
int T, n, m, k;
int a[N];
int dp[N];

void solve()
{
    fill(dp, dp + n, -INF);
    dp[0] = 0;
    rep(i,2,n+1){
        rep(j,0,n-i){
            dp[i + j - 1] = max(dp[i + j - 1], dp[j] + a[i]);
        }
    }
    printf("%d\n", dp[n - 2] + n * a[1]);
}

int main()
{
    for (scanf("%d", &T); T;T--){
        scanf("%d", &n);
        rep(i,1,n){
            scanf("%d", a + i);
            if(i!=1) a[i] -= a[1];
        }
        solve();
    }
    return 0;
}
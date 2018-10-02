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

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;
int T, n, m, k;
int a[N];
int dp[N];
int solve()
{
    fill(dp, dp + n, INF);
    rep(i,0,n){
        *upper_bound(dp, dp + n, a[i]) = a[i];
    }
    return lower_bound(dp, dp + n, INF) - dp;
}
int main()
{
    for (scanf("%d", &T); T;T--){
        scanf("%d", &n);
        rep(i,0,n){
            scanf("%d", &a[i]);
        }

        int len = solve();
        if(len>=n-1){
            printf("YES\n");
        }
        else{
            rep(i,0,n){
                a[i] = INF - a[i];
            }
            len = solve();
            // printf("%d\n", len);
            if(len>=n-1){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
    return 0;
}
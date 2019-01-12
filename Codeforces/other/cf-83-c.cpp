#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e6+7;
int t,n,m;
ll s[N],a[2][N], p[2][N],ans,r,d;
int main()
{
    scanf("%d",&n);
    rep(i,0,2){
        rep(j,0,n){
            scanf("%d",&a[i][j]);
        }
    }

    per(i,0,n) s[i] = s[i+1] + a[0][i] + a[1][i];
    per(i,0,n) p[0][i] = p[0][i+1] + s[i+1] + ((n-i)*2 - 1)*a[1][i];
    per(i,0,n) p[1][i] = p[1][i+1] + s[i+1] + ((n-i)*2 - 1)*a[0][i];

    rep(i,0,n){
        ans = max(ans, p[i&1][i] + s[i]*i*2 + r);
        r += d*a[i&1][i];d++;
        r += d*a[(i+1)&1][i];d++;
    }

    printf("%lld\n",ans);
    return 0;
}

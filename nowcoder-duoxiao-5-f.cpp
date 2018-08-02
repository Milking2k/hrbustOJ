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
const ll mod=998244353;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
const int N = 1e5+7;
const int INV100 = 828542813;
int n, p[N], d[N], x[N], tot;
int b[N];
 
void add(int x, int k) {
    while(x <= n) {
        b[x] = 1ll * b[x] * k % mod;
        x += x & -x;
    }
}
 
int sum(int x) {
    int ret = 1;
    while(0 < x) {
        ret = 1ll * ret * b[x] % mod;
        x -= x & -x;
    }
    return ret;
}
 
int main()
{
    scanf("%d",&n);
    rep(i,1,n+1) {
        scanf("%d%d",p+i,d+i);
        x[tot++] = d[i];
        b[i] = 1;
    }
 
    sort(x, x + tot);
    tot = unique(x, x + tot) - x;
 
    int ans = 0;
    rep(i, 1, n+1) {
        d[i] = upper_bound(x, x + tot, d[i]) - x;
        d[i] = tot - d[i] + 1;
    }
    rep(i, 1, n+1) {
        ans = (ans + (1ll * sum(d[i]) * p[i] % mod * INV100)) % mod;
        add(d[i], 1ll * (100 - p[i]) * INV100 % mod);
    }
 
    printf("%d\n", ans);
    return 0;
}
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
const int N = 1e5+7;
int T,n,m;
int a[N];
ll sum[N];
 
void init()
{
    rep(i,2,1e5+2){
        sum[i] = (n-1)*sum[i - 1] % mod;
    }
    ll cnt = sum[0];
    rep(i,1,1e5+2){
        sum[i] = (sum[i] - cnt+mod)%mod;
        cnt = sum[i];
    }
}
 
int main()
{
    rep(i, 0, 1e5 + 6) sum[i] = 0;
    read(n), read(m);
    rep(i, 1, n + 1){
        read(a[i]);
        sum[1] += a[i];
    }
 
    init();
 
    rep(i,1,m+1){
        int x, t;
        read(x), read(t);
        ll ans = sum[t];
        if(t&1)
            ans = (ans - a[x]+mod) % mod;
        else
            ans = (ans + a[x]) % mod;
        printf("%lld\n", ans%mod);
    }
    return 0;
}

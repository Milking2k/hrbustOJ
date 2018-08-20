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
const ll mod = 998244353;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e5+7;
int T,n,m;
int a[N];
int main()
{
    int a, b, c, d;
    for (read(T); T;T--){
        read(a);
        read(b);
        read(c);
        read(d);
        ll ans1 = (((0ll + b + d + 1) % mod) * powmod(2, 0ll + a + c)) % mod;
        ll ans2 = powmod(2, 0ll + a + b);
        ll ans3 = (((b + 1) * powmod(2, a) % mod) % mod);
        printf("%lld\n", (ans1+ans2-ans3+2ll*mod)%mod);
    }
        return 0;
}
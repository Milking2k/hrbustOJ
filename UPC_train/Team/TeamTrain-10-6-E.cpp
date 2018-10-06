#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
// #define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
#define Mod(a,b) a<b?a:a%b+b
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
const int N = 100010;
 
ll n,q,m,a[N];
map<ll,ll> mp;
ll qcmod(ll x,ll n,ll mod){ll res=1;while(n){if (n&1) res=Mod(res*x,mod),n--;x=Mod(x*x,mod); n>>=1;}return res;}
 
 
ll phi(ll k)
{
    ll i,s=k,x=k;
    if (mp.count(k)) return mp[x];
    for(i = 2;i * i <= k; i++)
    {
        if(k % i == 0) s = s / i * (i - 1);
        while(k % i == 0) k /= i;
    }
    if(k > 1) s = s / k * (k - 1);
    mp[x]=s; return s;
}
 
ll solve(ll l,ll mod)
{
    if (l==1||mod==1) return Mod(l,mod);
    ll res = qcmod(l,solve(l-1,phi(mod)),mod);
    // printf("%lld\n", res);
    return res;
}
 
int main()
{
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",solve(n,m)%m);
    return 0;
}
 

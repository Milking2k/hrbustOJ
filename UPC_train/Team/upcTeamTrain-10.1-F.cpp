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
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
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
int T, n, k, Cas = 0;
ll sum, ans, m;
vector<int> b,yinzi;
ll phi(ll n)
{
    ll t = 1, i;
    if (!(n & 1))for (n >>= 1; !(n & 1); n >>= 1, t <<= 1);
    for (i = 3; i * i <= n; i += 2)if (n % i == 0)
        for (n /= i, t *= i-1; n % i == 0; n /= i, t *= i);
    if (n > 1) t *= n-1;
    return t;
}
void init(int n)
{
    for (int i = 2; i * i <= n;i++){
        if(i*i==m) yinzi.pb(m / i);
        else if(n%i==0){
            yinzi.pb(i);
            yinzi.pb(n / i);
        }
    }
    my_sort_unique(yinzi);
}

void solve()
{
    sum = 0, ans = 0;
    bool ok = 0;
    scanf("%d%lld", &n, &m);
    rep(i,1,n+1){
        ll x;
        scanf("%lld", &x);
        int cnt = gcd(x, m);
        b.pb(cnt);
        if(cnt==1) ok = 1;
    }
    if(ok){
        printf("Case #%d: %lld\n",++Cas, m*(m-1)/2);
    }
    else{
        init(m);
        my_sort_unique(b);
        
        for(auto u:yinzi){
            for(auto v:b){
                if(u%v==0){
                    sum += phi(m / u) * m / 2;
                    break;
                }
            }
        }
        printf("Case #%d: %lld\n",++Cas, sum);
    }
}

int main()
{
    for (scanf("%d", &T); T;T--){
        solve();
        b.clear();
        yinzi.clear();
    }
    return 0;
}
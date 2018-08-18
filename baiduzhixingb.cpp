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
int T,n,m,k;
int l[107],r[107];
//int a[N];
//int lo,hi;

ll inv(ll a, ll b){
    if(a == 1)return 1;
    return inv(b%a,b)*(b-b/a)%b;
}
ll solve(int l, int r)
{
    if(r<l) return 0;
    else return (ll) (l+r)*(r-l+1)/2;
}

ll get(int x, int y){
    ll ans = 1;
    rep(i,0,n){
        int l1 = l[i];
        int r1 = min(r[i], x);
        ans = ans*solve(y+1-r1, y+1-l1)%mod;
    }
    return ans;
}

int main()
{
    for(scanf("%d",&T);T;T--){
        int lmax=-1,rmax=-1;
        ll temp = 1;
        scanf("%d",&n);
        rep(i,0,n){
            int x,y;
            scanf("%d%d",&x,&y);
            l[i] = x,r[i] = y;
//            lmax = max(lmax, l[i]);
//            rmax = max(rmax, r[i]);
            lmax = max(lmax, l[i]);
            rmax = max(rmax, r[i]);
            temp = temp*(r[i]-l[i]+1)%mod;
        }
        ll ans = 0;
        rep(i,lmax,rmax+1){
            ans = (ans+(get(i,i)-get(i-1,i)+mod)%mod)%mod;
        }
        ans = ans*inv(temp,mod)%mod;
        printf("%d\n",(int)ans);
    }

    return 0;
}

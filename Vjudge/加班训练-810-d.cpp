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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e5+7;
int T,n,m;
ll pre[N];

int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%d",&n);
        pre[0] = 0;
        rep(i,1,n+1){
            int x;
            scanf("%d",&x);
            pre[i] = pre[i-1] + x;
        }
        ll ans = 0;
        for(ll k = 1;k<=34;k++){
            ll l = 1,r=0;
            ll lmax = 1ll<<(k-1);
            ll rmax = (1ll<<k)-1;
            if(k==1) lmax = 0;
            for(ll i = 1;i<=n;i++){
                l = max(i,l);
                while(l<=n && pre[l]-pre[i-1] < lmax) l++;
                r = max(l-1,r);
                while(r+1<=n && pre[r+1]-pre[i-1] <= rmax && pre[r+1]-pre[i-1] >= lmax) r++;
                if(l>r) continue;
                ans += (i*(r-l+1)+(r+l)*(r-l+1)/2)*k;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

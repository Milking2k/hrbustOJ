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

const int N = 1e6+7;

int T,n,m,k;
ll maxnum,minnum;
ll a[N];
ll ans;

void solve()
{
    ll l=minnum,r=maxnum,mid;
    while(l<=r){
        mid = (l+r)/2;
        ll cnt1=0,cnt2=0;
        rep(i,1,n+1){
            if(a[i] > mid+1) cnt2 += (a[i]-mid)/2;
            else cnt1 += max(0ll, mid-a[i]);
        }
        if(cnt2 >= cnt1) l = mid+1,ans=1ll*mid;
        else r = mid-1;
    }
    printf("%lld\n",ans);
}

int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%d",&n);
        rep(i,1,n+1){
            scanf("%lld",a+i);
        }
        sort(a+1,a+1+n);
        minnum = a[1];
        maxnum = a[n];
        solve();
    }

    return 0;
}

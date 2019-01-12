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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e6+7;

int n,t,m,ret=-1;
int a[N];
int main()
{
    scanf("%d",&n);
    rep(i,1,2*n+1){
        scanf("%d",a+i);
    }

    sort(a+1,a+1+2*n);

    ll ans=0;
    ans = 1ll*(a[n]-a[1])*(a[2*n]-a[n+1]);

    rep(i,n+1,2*n+1){
        ans = min(ans, 1ll*(a[2*n]-a[1])*(a[i]-a[i-n+1]));
    }

    printf("%lld\n",ans);
    return 0;
}





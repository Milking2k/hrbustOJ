#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,n) for (ll i=a;i<=n;i++)
#define maxn 1000000007
typedef vector<int> VI;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

unsigned ll r,l,n,emt[20000001],v[20000001],ny[20000001],cnt2=0,ans=0;
int main(){
    scanf("%lld%lld",&l,&r);
    n=r-l+1;
    emt[0]=1;
    rep(i,1,n)
        emt[i]=emt[i-1]*i%maxn;

    rep(i,l,r){
    	if(v[i])continue;
    	cnt2++;
    	for(ll j=2;j*i<=r;j++)
            v[i*j]=1;
    }
    ny[n-cnt2]=powmod(emt[n-cnt2],maxn-2);

    for(ll i=n-1;i>=cnt2;i--)
        ny[i-cnt2]=ny[i+1-cnt2]*(i+1-cnt2)%maxn;
    rep(i,cnt2,n)
        ans=(ans+cnt2*emt[i]%maxn*emt[n-cnt2]%maxn*ny[i-cnt2]%maxn)%maxn;
    printf("%lld",ans);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define mod 998244353
typedef long long LL;
int n,m,T;
LL fac[200001];
LL power(LL x,LL y)
{
    LL ans=1;
    while (y)
    {
        if (y&1) ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d",&T);
    fac[1]=1;
    for (int i=2;i<=200000;i++) fac[i]=fac[i-1]*i%mod;
    for (int ii=1;ii<=T;ii++)
    {
        scanf("%d",&n);
        n--;
        printf("Case #%d: %lld\n",ii,3LL*fac[2*n]*power(fac[n+2]*fac[n-1]%mod,mod-2)%mod);
    }
    return 0;
}
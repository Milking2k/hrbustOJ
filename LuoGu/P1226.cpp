#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll b,p,k;

ll quickmod(ll x,ll n,ll m)
{
    ll res=1;
    while(n>0)
    {
        if(n&1) res = (res*x)%m;
        x = (x*x)%m;
        n >>= 1;
    }
    return  res;
}
int main()
{
    scanf("%lld %lld %lld",&b,&p,&k);

    if(p==0) return !printf("%lld^%lld mod %lld=%lld\n",b,p,k,1%k);

    return !printf("%lld^%lld mod %lld=%lld\n",b,p,k,quickmod(b,p,k));
}

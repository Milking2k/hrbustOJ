/*
    max k;
    k^2 - h1*(h1-1)/2 <= n;
    h1=min(k,H).
    解方程 or 二分查找;
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 2e9;
ll n,h;

bool check(ll maxh)
{
    ll k = min(h,maxh);
    ll cnt = maxh*maxh-k*(k-1)/2;
    return (cnt<=n);
}

ll get(ll maxh)
{
    ll k = min(h,maxh);
    ll cnt = maxh*maxh-k*(k-1)/2;\
    ll len = (2*maxh-1)-(k-1);
    n -= cnt;
    return len + (n+maxh-1)/maxh;
}
int main()
{
    scanf("%lld%lld",&n,&h);
    ll l=1,r=INF;
    while(l<r-1)
    {
        ll m = (l+r)/2;
        if(check(m))
            l = m;
        else
            r = m;
    }
    printf("%lld\n",check(r)?get(r):get(l));
    return 0;
}
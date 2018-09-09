#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD = 1e9;
int n,m,t;

LL powerl(LL x, LL n, LL m)
{
    LL res = 1;
    while (n > 0){
        if  (n & 1)
            res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        LL a,n,l;
        scanf("%lld%lld%lld",&a,&n,&l);

        long long ans = (powerl(2, n, l)-1+l)%l;
        ans = ((a+5)*ans)%l;
        ans = (ans - 5*n%l + l)%l;
        printf("%lld\n",ans%l);
    }
    return 0;
}

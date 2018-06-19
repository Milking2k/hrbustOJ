//#include<bits/stdc++.h>
//using namespace std;
//
//int n,m,t;
//int main()
//{
//    scanf("%d",&t);
//    while(t--)
//    {
//
//
//
//    }
//    return 0;
//}

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1e9+7;
int n,m,t;

LL powerMod(LL x, LL n, LL m)
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
        long long ans = powerMod(2, n, MOD);

        ans = ((a+5)*(ans-1))%MOD;
        ans = (ans - 5*n%l)%MOD;
        printf("%lld\n",ans%l);
    }
    return 0;
}

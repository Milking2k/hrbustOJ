#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int mod = 1000000007;
const int inf = 1000000007;
__int64 quick_mod(__int64 a,__int64 b)
{
    __int64 ans=1;
    a%=mod;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod;
            b--;
        }
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
__int64 C(__int64 n,__int64 m)
{
    if(m>n) return 0;
    __int64 ans=1;
    for(int i=1;i<=m;i++)
    {
        __int64 a=(n+i-m)%mod;
        __int64 b=i%mod;
        ans=ans*(a*quick_mod(b,mod-2)%mod)%mod;
    }
    return ans;
}
__int64 Lucas(__int64 n,__int64 m)
{
    if(m==0) return 1;
    return C(n%mod,m%mod)*Lucas(n/mod,m/mod)%mod;
}
int main()
{
    int a,d,m,i;
    while(~scanf("%d%d%d%d",&a,&d,&m,&i))
    {
        printf("%I64d\n",(Lucas(i+m-1,m)*a+Lucas(i+m-1,m+1)*d)%mod);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;


LL qmod(LL a, LL b)
{
    if (b == 0) return 1;
    LL r = a % MOD;
    LL k = 1;
    while (b > 1){
        if ((b & 1)!=0)
            k = (k * r) % MOD;
        r = (r * r) % MOD;
        b >>= 1;
    }
    return (r * k) % MOD;
}
int main()
{
    LL n;
    scanf("%lld",&n);
    LL ans=(24LL-42LL*n+23*qmod(n,2)-6*qmod(n,3)+qmod(n,4)+MOD+MOD)%MOD;
    LL qw=qmod(24,MOD-2);
    printf("%lld\n",(ans*qw)%MOD);
    return 0;
}

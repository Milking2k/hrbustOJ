#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=1e5+7;
char a[maxn];
const LL MOD=1e9+7;
const LL mod=1e9+6;
int len;

LL solve()
{
    LL qw=0;
    for(int i=1;i<=len;i++){
        qw*=10;
        qw+=a[i]-'0';
        if(qw>mod){
            qw%=mod;
        }
    }
    qw=(qw-1+mod)%mod;
    return qw;
}

LL qmod(LL a, LL b,LL p)
{
    if (b == 0) return 1;
    LL r = a % p;
    LL k = 1;
    while (b > 1){
        if ((b & 1)!=0)
            k = (k * r) % p;
        r = (r * r) %p;
        b >>= 1;
    }
    return (r * k) % p;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",a+1);
        len=strlen(a+1);
        LL as=solve();
        LL ans=qmod(2,as,MOD);
        printf("%lld\n",ans);
    }
    return 0;
}
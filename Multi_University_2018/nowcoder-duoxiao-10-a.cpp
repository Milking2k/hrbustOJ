#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL read()
{
    LL x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
 
const int  MOD=998244353;
 
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
const int maxn=1e5+7;
LL a[maxn];
LL pre[maxn];
int main()
{
    int T=read();
    while(T--){
        LL n,m;
        n=read(),m=read();
        for(int i=1;i<=n;i++)a[i]=read();
        pre[0]=0;
        LL as=qmod(2,m*n);
        for(int i=1;i<=n;i++)pre[i]=(pre[i-1]+a[i])%MOD;
        while(m--){
            int op=read();
            int l=read(),r=read();
            if(op==2){
                LL ans=(pre[r]-pre[l-1]+MOD)%MOD;
                printf("%lld\n",(as*ans)%MOD);
            }
        }
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1e9+7;
 
const int maxn=1e4+7;
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
int f[maxn+10];
void init(){//阶乘
    f[0]=1;
    for(int i=1;i<=maxn;i++){
        f[i]=(long long)f[i-1]*i%MOD;
    }
}

int fast(int a,int n){
    if(n==0)return 1;
    if(n%2)return (long long)a*fast(a,n-1)%MOD;
    int tmp=fast(a,n/2);
    return (long long)tmp*tmp%MOD;
}

int C(int n,int m){
    if(n==m||m==0)return 1;
    return ((long long)f[n]*fast(f[m],MOD-2)%MOD)*fast(f[n-m],MOD-2)%MOD;
}

LL Lucas(LL n, LL m)
{
    if(m == 0) return 1;
    return C(n % MOD, m % MOD) * Lucas(n /MOD, m /MOD) %MOD;
}
LL pf[maxn];
LL solve(int x)
{
    LL res=0;
    for(int i=2;i<=x;i++){
        LL as=(f[x]*pf[i])%MOD;
        if(i&1){
            res=(res-as+MOD)%MOD;
        }
        else res=(res+as)%MOD;
    }
    return res;
}
int main()
{
    int T;
    LL ans=1;
    for(int i=1;i<=maxn;i++){
        ans=(ans*i)%MOD;
        f[i]=ans;
        pf[i]=qmod(ans,MOD-2);
    }
    init();
//    printf("%lld\n",Lucas(10000,5000));
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        ans=0;
//        printf("test %lld\n",solve(0));
        for(int i=n;i>n-k;i--){
//                printf("test %d\n",i);
            LL as=(C(n,i)*solve(i))%MOD;
            ans=(ans+as)%MOD;
//            printf("test %d %lld %lld %lld\n",i,ans,solve(i),Lucas(n,i));
        }
        printf("%lld\n",(f[n]-ans+MOD)%MOD);
    }
    return 0;
}
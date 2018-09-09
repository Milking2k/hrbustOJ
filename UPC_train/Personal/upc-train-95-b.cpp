#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
const LL MOD=1e9+7;
LL a[105];
LL b[105];
LL c[maxn];
void check(LL x)
{
    for(int i=0;i<=65;i++)b[i]=0;
    int i=0;
    while(x){
        b[i]=x%2;
        x/=2;
        i++;
    }
}
bool solve()
{
    bool oo=true;
    for(int i=60;i>=1;i--){
        if(a[i]>=b[i]){
            a[i]-=b[i];
        }
        else{
            b[i]-=a[i];
            b[i-1]+=2*b[i];
            b[i]=0;a[i]=0;
//            printf("fuck %d b[i]==%d\n",i,b[i-1]);
        }
    }
    a[0]-=b[0];
    if(a[0]<0){
        return false;
    }
    return true;
}
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
LL calc()
{
    LL ans=0;
    for(int i=0;i<=59;i++){
        a[i]%=MOD;
        ans+=(a[i]*qmod(2,i))%MOD;
        ans%=MOD;
    }
    return ans;
}
int main()
{
//    printf("%d\n",qmod(2,0));
    for(int i=0;i<60;i++){
        scanf("%lld",&a[i]);
    }
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&c[i]);
    }
    bool ok=true;
    for(int i=1;i<=n;i++){
        check(c[i]);
        ok=solve();
        if(!ok)break;
    }
    if(!ok){
        puts("-1");
    }
    else{
        printf("%lld\n",calc()%MOD);
    }
    return 0;
}
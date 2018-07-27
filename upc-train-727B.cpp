#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MOD = 998244353;
int t,n,m,s;
int emt[100007];
const int mod = 998244353;
typedef long long ll;
long long quickpow(long long a, long long b) {
    if (b < 0) return 0;
    long long ret = 1;
    a %= mod;
    while(b) {
        if (b & 1) ret = (ret * a) % mod;
        b >>= 1;
        a = (a * a) % mod;
    }
    return ret;
}
//long long inv(long long a) {
//    return quickpow(a, mod - 2);
//}

ll gcd(ll a,ll b){
 if(a%b==0)
  return b;
 return gcd(b,a%b);
}

ll toNpow(ll n)
{
  if(n==0)return 1;
  return n*toNpow(n-1)%MOD;
}


ll extend_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    else {
        ll r = extend_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}
ll inv(ll a, ll n) {
    ll x, y;
    extend_gcd(a, n, x, y);
    x = (x % n + n) % n;
    return x;
}

int main()
{
    scanf("%d%d\n",&n,&s);
    for(int i=1;i<=n;i++){
        scanf("%d",&emt[i]);
    }
    sort(emt+1,emt+1+n,[](int a,int b){return a>b;});
    long long fenzi=1;
    long long fenmu=1;
    long long cont=0;

    long long cnt2=0;
    for(int i=1;i<=n;i++) {
        if(emt[i]<s){
            cnt2 = (cnt2+emt[i]*emt[i]%MOD+MOD)%MOD;
        }
    }
//    printf("fenzi:%lld\n",cnt2);
    fenzi = quickpow(s,n-2)*(cnt2)%MOD;
    fenzi = fenzi*(s*s-cnt2 + 10ll*MOD)%MOD;
    fenmu = toNpow(0ll+n);
//    for(int i=1;i<=n;i++){
//        if(emt[i]>=s){
//            fenzi=(fenzi*(s)%MOD);
//            fenmu=fenmu*i%MOD;
//        }
//        else{
//            long long cnt = 0ll+(s*s%MOD-emt[i]*emt[i]%MOD+MOD)%MOD;
//            long long cnt2 = fenzi*s%MOD;
//            fenzi=fenzi*cnt%MOD;
//            fenmu=fenmu*i%MOD;
//            cont++;
//        }
//    }
//    for(int i=1;i<=cont;i++){
//        fenmu=(fenmu*(s*s%MOD)%MOD);
//    }

//    printf("fenzi:%lld\n",fenzi);
//    printf("fenmu:%lld\n",fenmu);
    long long cgcd = gcd(fenzi,fenmu);
//    printf("fenmu:%lld\n",cgcd);
    fenzi=(fenzi/cgcd)%MOD;
    fenmu=(fenmu/cgcd)%MOD;
    fenzi=(fenzi/fenmu)%MOD;
//    printf("fenzi:%lld\n",fenzi);
//    printf("fenmu:%lld\n",fenmu);
    ll ans = (fenzi+inv(fenmu,MOD)+MOD)%MOD;
    if(fenmu==1) ans = fenzi;
    printf("%lld\n",ans);
    return 0;
}

/*

3 3
3 2 2
*/

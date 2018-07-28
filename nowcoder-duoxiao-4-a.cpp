//#include<bits/stdc++.h>
//using namespace std;
//typedef long long ll;
//int t,n,m;
//ll ans=0;
//char s[100007];
//long long gao[100] = {1000000007, 1000000006, 500000002, 243900800, 79872000, 19660800, 5242880};//to 6
//
//ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
//
//ll Mod(ll x, ll y)
//{
//    if(x<y) return x;
//    return (x+y)%y;
//}
//
//
//ll getgao(ll i){
//    if(i<28) return gao[i];
//    return 1ll;
//}
//
//int main()
//{
//    int t;
//    scanf("%d",&t);
//
//    ll i = 1<<21;
//    ll pos=7;
//    while(i>=2){
//        gao[pos] = i;
//        i>>=1;
//        pos++;
//    }
//
//    while(t--){
//        scanf("%s",s);
//        ans=0;
//        ll p=0;
//        int len = strlen(s);
//        for(int i=0;i<len;i++) {
//            if(s[i]=='2') p+=1;
//        }
//
//        for(int i=0;i<len;i++) {
//            if(s[i]=='0'){
//                ans = (ans+1+getgao(p)) % getgao(p);
////                printf("i:%d %lld\n",i,getgao(p));
//            }
//            else if(s[i]=='1'){
//                ans = 2*((ans+1+getgao(p)) % getgao(p)) % getgao(p);
////                printf("i:%d %lld\n",i,getgao(p));
//            }
//            else if(s[i]=='2'){
//                p-=1;
//                ll mod = getgao(p);
////                printf("s[%d]:%c %lld\n",i,s[i],getgao(p));
////                printf("ans+1:%lld getgao(%d+1):%lld mod:%lld\n",ans+1,p+1,getgao(p+1),mod);
//                ans = (3*powmod(2, ((ans+1+getgao(p+1))%(getgao(p+1))), mod) - 3 + mod) % mod;
//            }
//        }
//        printf("%lld\n", ans);
//    }
//    return 0;
//}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> m;

ll PH(ll x)
{
    ll res=x,a=x;
    for(ll i=2;i*i<=x;i++)
    {
        if(a%i==0)
        {
            res=res/i*(i-1);
            while(a%i==0) a/=i;
        }
    }
    if(a>1) res=res/a*(a-1);
    return res;
}
ll quick_pow(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
char s[100005];

ll dfs(ll i,ll mod)
{
    if(i==0) return 0;
    else if(s[i]=='0') return (dfs(i-1,mod)+1)%mod;
    else if(s[i]=='2') return ((3ll*quick_pow(2,dfs(i-1,m[mod])+1,mod)-3)%mod+mod)%mod;
    else return (2*dfs(i-1,mod)+2)%mod;
}
int main()
{
    ll mo=1e9+7;
    while(mo!=1)
    {
        m[mo]=PH(mo);
        mo=m[mo];
    }
    m[1]=1;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        cin>>s+1;
        int n=strlen(s+1);
        printf("%lld\n",dfs(n,1000000007));
    }
    return 0;
}
/*
1  x+2
2  3*2^(x+1)-x
0 x+1
*/

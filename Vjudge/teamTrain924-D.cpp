#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD=1e9+7;
LL qmod(LL a,LL b,LL p)
{
    if(b==0)return 1;
    LL r=a%p;
    LL k=1;
    while(b>1){
        if((b&1)!=0){
            k=(k*r)%p;
        }
        r=(r*r)%p;
        b>>=1;
    }
    return (r*k)%p;
}
const int maxn=3e5+7;
int a[maxn];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        int cnt=0;
        LL res=0;
        for(int i=1;i<=n;i++){
            scanf("%1d",&a[i]);
        }
        for(int i=1;i<=n;i++){
//            printf("%d",a[i]);
            res*=10;
            res+=a[i];
            if(res>=m)res%=m;
            if(res==0)cnt++,res=0;
        }
        cnt--;
        if(res!=0)cnt=-1;
//        printf("test %d\n",res);C
        if(cnt==-1){
            printf("0\n");
        }
        else{
            LL ans=qmod(2ll,cnt,MOD);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
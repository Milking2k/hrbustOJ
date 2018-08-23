#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
int main()
{
    LL n;
    while(~scanf("%lld",&n)){
        if(n==0)break;
        LL ans1=n,ans2=1;
        LL zz=sqrt(2*n)+10;
        for(LL i=min(n,zz);i>=1;i--){
//            printf("test %d\n",i);
            LL now=i;
            LL as=2*n-now*(now-1);
            LL qw=2*now;
//            printf("test %d %d bool==%d\n",as,qw,as%qw);
            if(as%qw==0){
                if(now>ans2&&as/qw>=1){
                    ans2=now;
                    ans1=as/qw;
                }
            }
            now=n/i;
            as=2*n-now*(now-1);
            qw=2*now;
//            printf("fuck %d %d bool==%d\n",as,qw,as%qw);
            if(as%qw==0){
                if(now>ans2&&as/qw>=1){
                    ans2=now;
                    ans1=as/qw;
                }
            }
        }
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}

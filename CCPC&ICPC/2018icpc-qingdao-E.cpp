#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=2e5+7;
int n;
LL m;
LL a[maxn];
LL now[maxn];

bool check(LL x)
{
    LL cnt=0;
    for(int i=0;i<=n+1;i++)now[i]=0;
    for(int i=1;i<=n;i++){
        now[i]+=a[i];cnt++;
        if(now[i]>=x)continue;
        LL as=(x-now[i])/a[i];
        if((x-now[i])%a[i] > 0 )as++;
        now[i]+=as*a[i];
        now[i+1]+=as*a[i+1];
        cnt+=2LL*as;
        if(i==n-1){
            if(now[i+1]>=x)break;
        }
    }
//    for(int i=1;i<=n;i++){
//        printf("%lld ",now[i]);
//    }
//    puts("");
//    printf("fuck %lld\n",cnt);
    if(cnt<=m)return true;
    return false;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        LL maxx=-1;
        scanf("%d%lld",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            maxx=max(maxx,a[i]*m);
        }
//        if(n==1){
//            printf("%lld\n",a[1]);
//            continue;
//        }
        LL L=0,R=maxx,ans=0;
        while(L<=R){
            LL mid=(L+R)>>1;
            bool as=check(mid);
//            printf("test %lld %lld %lld %d\n",L,R,mid,as);
            if(as){
                L=mid+1;ans=max(ans,mid);
            }
            else R=mid-1;
        }
//        for(int i=1;i<=n;i++){
//            printf("%lld ",now[i]);
//        }
//        puts("");
//        for(int i=1;i<=n/2;i++)swap(a[i],a[n-i+1]);
//        L=0,R=1e18;
//        while(L<=R){
//            LL mid=(L+R)>>1;
//            if(check(mid)){
//                L=mid+1;ans=max(ans,mid);
//            }
//            else R=mid-1;
//        }
        printf("%lld\n",ans);
    }
    return 0;
}
/*
2
4 8
3 2 6 6
3 9
10 10 1

1
3 9
10 10 1

1
4 4
1 1 1 1


1
2 1
100000 100000
*/
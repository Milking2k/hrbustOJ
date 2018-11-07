#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=1e5+7;
int a[maxn];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==0)cnt++;
        }
        if(m==n){
            puts("Richman");continue;
        }
        if(cnt>m){
            puts("Impossible");continue;
        }
        m-=cnt;
        LL ans=0;
        if(m==0){
            LL minn=0x3f3f3f3f;
            for(int i=1;i<=n;i++){
                if(a[i]==0)continue;
                if(a[i]<minn)minn=a[i];
            }
            printf("%lld\n",max(minn-1,0ll));
            continue;
        }
        int i,j=0;
//        printf("aaa %d\n",m);
        for(i=1;i<=n&&j<m;i++){
            if(a[i]==0)continue;
            j++;ans+=a[i];
//            printf("test %d %d %lld\n",i,j,ans);
        }
        LL minn=0x3f3f3f3f;
        for(;i<=n;i++){
            if(a[i]==0)continue;
            if(a[i]<minn)minn=a[i];
        }
        ans+=max(minn-1,0ll);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
4
4 2
1 2 4 8
4 0
100 99 98 97
2 2
10000 10000
5 3
0 0 0 0 1


1
4 2
1 2 4 8

*/
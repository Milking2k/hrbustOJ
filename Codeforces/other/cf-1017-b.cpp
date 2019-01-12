#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+7;
int a[maxn],b[maxn];
int pre10[maxn];
int pre01[maxn];
int pre00[maxn];
int pre11[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%1d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%1d",&b[i]);
    }
    for(int i=n;i>=1;i--){
        if(a[i]==0&&b[i]==0)pre00[i]++;
        if(a[i]==1&&b[i]==1)pre11[i]++;
        if(a[i]==0&&b[i]==1)pre01[i]++;
        if(a[i]==1&&b[i]==0)pre10[i]++;
    }
    for(int i=n;i>=1;i--){
        pre00[i]+=pre00[i+1];
        pre11[i]+=pre11[i+1];
        pre01[i]+=pre01[i+1];
        pre10[i]+=pre10[i+1];
    }
//    for(int i=1;i<=n;i++){
//        printf("test %d %d %d %d\n",pre00[i],pre01[i],pre10[i],pre11[i]);
//    }
//    puts("");
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==0&&b[i]==0){
            ans+=pre11[i+1]+pre10[i+1];
        }
        if(a[i]==1&&b[i]==1){
            ans+=pre00[i+1];
        }
        if(a[i]==1&&b[i]==0){
            ans+=pre01[i+1]+pre00[i+1];
        }
        if(a[i]==0&&b[i]==1){
            ans+=pre10[i+1];
        }
    }
    printf("%lld\n",ans);
    return 0;
}

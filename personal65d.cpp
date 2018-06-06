#include<stdio.h>
#define max(a,b) (a)>(b)?(a):(b)
int main()
{
    int n;
    int a[100005];
    while(~scanf("%d",&n)){
        int vis[100050]={0},i;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int maxz=-1;
        for(i=1;i<=n;i++){
            vis[a[i]]=vis[a[i]-1]+1;
            maxz=max(maxz,vis[a[i]]);
        }
        printf("%d\n",n-maxz);
    }
    return 0;
}
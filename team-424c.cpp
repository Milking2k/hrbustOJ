#include <bits/stdc++.h>
using namespace std;
 
const int maxn=2e5+7;
 
int n,m;
int a[maxn],b[maxn];
//bool vis[maxn];
 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans=0;
//    memset(vis,false,sizeof(vis));
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int i=1,j=1;
    while(i<=n&&j<=m){
        if(a[i]<=b[j]){
//            vis[i]=true;
            ans++;
            i++,j++;
        }
        else{
            j++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
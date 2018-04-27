#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int n;
struct node
{
    int x,y;
}a[1005];
const int INF=0x3f3f3f3f;
int main()
{
    scanf("%d",&n);
    LL sum=0;
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    int l=INF,r=-INF,u=-INF,d=INF;
    for(int i=0;i<n;i++){
        if(a[i].x==a[(i+1)%n].x){
            sum+=abs(a[i].y-a[(i+1)%n].y);
        }
        else{
            sum+=abs(a[i].x-a[(i+1)%n].x);
        }
        l=min(l,a[i].x);
        r=max(r,a[i].x);
        d=min(d,a[i].y);
        u=max(u,a[i].y);
    }
//    printf("%d %d %d\n",sum,lena,lenb);
    printf("%lld\n",sum-2*(r-l+u-d));
    return 0;
}
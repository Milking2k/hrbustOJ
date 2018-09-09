#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=449;
const double eps=1e-15;
typedef long long LL;
struct node{
    double x,y;
}a[maxn];
int vis[maxn];
 
int main() {
    int n;
    read(n);
    for(int i=1;i<=n;i++) {
        scanf("%lf%lf",&a[i].x,&a[i].y);
    }
    int ans=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j)continue;
            double dx=a[i].x-a[j].x;
            double dy=a[i].y-a[j].y;
            double d;
            if(dx==0)d=9999999999.999999;
            else d=dy/dx;
            memset(vis,0,sizeof(vis));
            int temp=0;
            for(int ii=1;ii<=n;ii++) {
                for(int jj=1;jj<=n;jj++) {
                    if(ii==jj)continue;
                    double ddx=a[ii].x-a[jj].x;
                    double ddy=a[ii].y-a[jj].y;
                    double dd;
                    if(ddx==0)dd=9999999999.999999;
                    else dd=ddy/ddx;
                    if(dd - d < eps && !vis[ii] && !vis[jj]) {
                        temp++;
                        vis[ii]=1;
                        vis[jj]=1;
                    }
                }
            }
            ans=max(ans,temp);
        }
    }
    printf("%d\n",ans*(ans-1)/2);
}
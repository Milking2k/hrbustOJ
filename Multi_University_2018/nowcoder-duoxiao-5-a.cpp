#include <bits/stdc++.h>
using namespace std;
 
const double eps=1e-7;
const int maxn=1e5+7;
double a[maxn],b[maxn],d[maxn];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lf",&a[i]);
        d[i]=a[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%lf",&b[i]);
    }
    for(int i=1;i<=n;i++){
        a[i]*=b[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=d[i];
    }
    double l=0.0,r=999999.0,mid;
        double ans;
        while((r-l)>eps){
            mid=(l+r)/2.0;
            for(int i=1;i<=n;i++){
                d[i]=a[i]-mid*b[i];
            }
            sort(d+1,d+1+n);
            ans=0.0;
            for(int i=k+1;i<=n;i++){
                ans+=d[i];
            }
            if(ans>0){
                l=mid;
            }
            else{
                r=mid;
            }
        }
        printf("%.7f\n",mid);
    return 0;
}
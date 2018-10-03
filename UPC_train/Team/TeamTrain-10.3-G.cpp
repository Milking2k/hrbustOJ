#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
int T,n,m;
int main()
{
    int Cas=0;
    while(~scanf("%d",&n) && n){
        double ans=0;
        double cnt1 = 15.5;
        double cnt2 = 32;
        double cnt3 = 40;
        for(int i=1;i<=n;i++){
            double a,b,c,d;
            scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
            ans += a*0.8+b+c*1.2+0.6*d;
            ans -= ((cnt1*a + cnt2*b + cnt3*c)/85);
        }
            printf("Case #%d: RM%.2lf\n",++Cas,ans);
    }

    return 0;
}

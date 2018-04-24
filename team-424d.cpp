#include <bits/stdc++.h>
using namespace std;
 
const int maxn=2e5+7;
 
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        double a;
        double b;
        scanf("%lf%lf",&a,&b);
        double ans2=a*60.0/b;
        double ans3=(a+1)*60.0/(b);
        double ans1=(a-1)*60.0/(b);
        printf("%.4f %.4f %.4f\n",ans1,ans2,ans3);
    }
}
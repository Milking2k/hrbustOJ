#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int eps = 0.0000000001;

int n;
int ans=0;
int main()
{
    while(~scanf("%d",&n))
    {
        ans=0;
        double x,y,v;
        for(int i=1;i<=n;i++)
        {
            scanf("%lf%lf%lf",&x,&y,&v);
            double cnt = sqrt((y-100)*(y-100) + x*x)/v;
            if(cnt<100 || fabs(cnt-100)<=eps) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
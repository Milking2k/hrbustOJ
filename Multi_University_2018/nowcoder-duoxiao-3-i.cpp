#include<stdio.h>
int n;
double ans[]={3,11./3,25./6,137./30,49./10,363./70,761./140,5.6580190484};
int main(){
    for(int i=1;i<=7;i++)
        scanf("%d",&n);
    printf("%.10f\n",ans[n-3]);
    return 0;
}

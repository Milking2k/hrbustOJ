#include<bits/stdc++.h>
using namespace std;
struct node{
    int tp;
    double val;
}emt[100007];
int t,n;
double k,c,p;
double dp[100007];
int main()
{
    scanf("%d%lf%lf%lf",&n,&k,&c,&p);
    for(int i=1;i<=n;i++){
        scanf("%d%lf",&emt[i].tp,&emt[i].val);
        if(emt[i].tp==2) emt[i].val=-emt[i].val;
    }

    for(int i=n;i>=1;i--){
        if(emt[i].tp==2)
            dp[i]=max(dp[i+1], dp[i+1]*(1+0.01*c)+emt[i].val);
        else
            dp[i]=max(dp[i+1], dp[i+1]*(1-0.01*k)+emt[i].val);
    }
    printf("%.2f\n",p*dp[1]);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn=77;
int dp[maxn][3];

int main()
{
    int n;
    int cas=1;
    memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    dp[2][0]=1;
    dp[3][0]=1;dp[3][1]=1;
    for(int i=4;i<=77;i++){
        dp[i][0]=dp[i-2][0]+dp[i-3][0];
        dp[i][1]=dp[i-1][0];
    }
    while(~scanf("%d",&n)){
        if(n==0)break;
        if(n==1)printf("Case #%d: %d\n",cas++,0);
        else if(n==2)printf("Case #%d: %d\n",cas++,0);
        else if(n==3)printf("Case #%d: %d\n",cas++,1);
        else printf("Case #%d: %d\n",cas++,dp[n][0]+dp[n][1]);
    }
    return 0;
}

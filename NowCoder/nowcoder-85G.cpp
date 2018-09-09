#include <bits/stdc++.h>
using namespace std;
#define MZ 1000000007
  
int dp[4005][2005];
  
int main()
{
    int n,m,now;
    scanf("%d",&n);
    memset(dp,-MZ,sizeof(dp));
    dp[1][1000]=0;
    for(int i=1;i<=4*n-3;i++)
    {
        if(i<n || i>3*n-2)
        {
            if(i<n)
                m=i;
            else
                m=4*n-2-i;
        }
        else
        {
            if(i%2==n%2)
                m=n;
            else
                m=n-1;
        }
        for(int j=1000-m+1;j<=1000+m-1;j+=2)
        {
            scanf("%d",&now);
            dp[i][j]+=now;
            dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]);
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
            dp[i+2][j]=max(dp[i+2][j],dp[i][j]);
        }
    }
    printf("%d\n",dp[4*n-3][1000]);
    return 0;
}
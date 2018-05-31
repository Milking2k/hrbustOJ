//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;

// --------------
int n;
int emt[100007];
int dp[100007];
int main()
{
    while(~scanf("%d",&n))
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&emt[i]);
            if(emt[i]==1)sum++,emt[i]=-1;
            else emt[i]=1;
        }
//        printf("%d\n",sum);
        if(sum==n)
        {
            printf("%d\n",n-1);
            continue;
        }
        int ans=0;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=max(dp[i-1]+emt[i],0);
            ans = max(ans,dp[i]);
        }
        ans+=sum;
        printf("%d\n",ans);
    }
    return 0;
}


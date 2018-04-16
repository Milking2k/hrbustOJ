#include <bits/stdc++.h>
using namespace std;

int n;
long long int  s,d;
long long int dp[1005];
int main()
{
    scanf("%d",&n);
    scanf("%lld%lld",&s,&d);
    dp[1] = s;
    for(int i=2;i<=n;i++)
    {
        scanf("%lld%lld",&s,&d);
        if(s <= dp[i-1])
        {
            dp[i] = dp[i-1] + abs(d-(dp[i-1]-s)%d);
        }else{
            dp[i] = s;
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
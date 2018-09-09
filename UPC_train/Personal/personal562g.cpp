#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int dp[207];

void init()
{
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=0;
    dp[4]=0;
    dp[5]=1;
    dp[6]=0;
    dp[7]=0;
    for(int i=8;i<207;i++)
    {
        dp[i] = min(dp[i-3],min(dp[i-4],dp[i-7]));
    }
}

int main()
{
    int n;
    int num;
    init();
    scanf("%d",&n);
    while(n--)
    {
//        printf("18:%d \n",dp[18]);
        scanf("%d",&num);
        if(num<150){printf("%d\n",num);continue;}
        num = dp[num/50]*50 + num%50;
        printf("%d\n",num);
    }
    return 0;
}

#include<stdio.h>///递归记忆化(递归+DP)
#include<string.h>
#define MOD 1000000007
#define ll long long
int dp[2003][2003],data[2002][2002];
int t,n,m;
ll ans;
void init()///1~2000所有数的因子
{
    memset(data,0,sizeof(data));
    memset(dp,0,sizeof(dp));///DP数组在所有测试数据中都通用，因此每组数据都会相应增加DP出来的数据以供下次使用
    for(int i=1;i<=2000;i++)
    {
        int flag=0;
        for(int j=1;j<=i;j++)
            if(i%j==0) data[i][++flag]=j;
        data[i][0]=flag;///模拟链表，0位存有多少因子，然后依次是数字i的因子分别是谁
    }
}
ll dfs(int now,int len)
{
    if(now==1||len==1)return 1;
    ll tmp=0;
    for(int i=1;i<=data[now][0];i++)
    {
        if(dp[len-1][data[now][i]])tmp=((tmp%MOD)+(dp[len-1][data[now][i]]%MOD))%MOD;
        else tmp=((tmp%MOD)+(dfs(data[now][i],len-1)%MOD))%MOD;
    }
    dp[len][now]=tmp;
    return tmp;
}
int main()
{
    init();
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&n,&m);
        for(int i=n;i>=1;i--) ans=((ans%MOD)+(dfs(i,m)%MOD))%MOD;
        printf("%lld\n",ans);
    }
}
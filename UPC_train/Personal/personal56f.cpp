#include<iostream>
#include<cstring>
#include<cstdio>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAXN = 50007;
int emtmax[MAXN][20],emtmin[MAXN][20];
void RMQ(int n)
{
    for(int j=1;j!=20;j++)
    {
        for(int i=1;i<=n;i++)
            if(i+(1<<j)-1 <= n)
            {
                emtmax[i][j] = max(emtmax[i][j-1],emtmax[i+(1<<(j-1))][j-1]);
                emtmin[i][j] = min(emtmin[i][j-1],emtmin[i+(1<<(j-1))][j-1]);
            }
    }
}


//int dp[MAXN][20];
//int mm[MAXN];
//void initRMQ(int n,int b[])
//{
//    mm[0] = -1;
//    for(int i=1;i<=n;i++)
//    {
//        mm[i] = ((i&(i-1)==0) ? mm[i-1]+1:mm[i-1]);
//        dp[i][0] = b[i];
//    }
//    for(int j=1;j<=mm[n];j++)
//        for(int i=1;i+(1<<j)-1<=n;i++)
//            dp[i][j] = max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
//}
//int rmqMax(int x,int y)
//{
//    int k = mm[y-x+1];
//    return max(dp[x][k], dp[y-(1<<k)+1][k]);
//}

int main()
{
    int n,q;
    while(~scanf("%d%d",&n,&q))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&emtmax[i][0]);
            emtmin[i][0] = emtmax[i][0];
        }
        RMQ(n);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int k = (int)(log(r-l+1.0)/log(2.0));
            printf("%d\n",max(emtmax[l][k],emtmax[r-(1<<k)+1][k])-min(emtmin[l][k],emtmin[r-(1<<k)+1][k]));
        }
    }
    return 0;
}

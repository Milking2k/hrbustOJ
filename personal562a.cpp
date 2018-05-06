
/*分析：
首先对于斜率dp我有个总结：
斜率dp一般应用于连续的一段或几段求最值
既1~k,k+1~j,j+1~...这样分段而不能跳开来求
只有连续段才能用单调队列维护最值然后
dp[i]=dp[j]+(j+1~i)的值。

对于本题：
题目要求m个子数组的最值，而子数组中的元素不一定是原数组连续的
所以肯定不能直接用斜率优化，经过分析可以发现先进行从小到大排序
然后连续的m段最值就是可以求最值了。

所以：先对原数组进行从小到大排序
dp[i][j]表示以i结尾的j段的最值
从k+1~i作为一段
则：dp[i][j]=dp[k][j-1]+(s[i]-s[k+1])^2
现在就是如何求到这个k使得dp[i][j]最小
假设k2<=k1<i
若:dp[k1][j-1]+(s[i]-s[k1+1])^2 <= dp[k2][j-1]+(s[i]-s[k2+1])^2
=>dp[k1][j-1]+s[k1+1]^2 - (dp[k2][j-1]+s[k2+1]^2) / (2s[k1+1]-2s[k2+1]) <= s[i]
所以:
y1 = dp[k1][j-1]+s[k1+1]^2
x1 = 2s[k1+1]
y2 = dp[k2][j-1]+s[k2+1]^2
x2 = 2s[k2+1]

=>(y1 - y2)/(x1 - x2) <= i
单调队列维护下凸折线
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#include <limits.h>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX = 10000+10;
int n,m,index;
int q[MAX];
int s[MAX],dp[2][MAX];

int GetY(int k1,int k2){
    return dp[index^1][k1]+s[k1+1]*s[k1+1] - (dp[index^1][k2]+s[k2+1]*s[k2+1]);
}

int GetX(int k1,int k2){
    return 2*(s[k1+1]-s[k2+1]);
}

int DP(){
    int head=0,tail=1;
    index=0;
    for(int i=1;i<=n;++i)dp[index][i]=INF;
    //dp[index][0]=0;
    for(int i=1;i<=m;++i){
        index=index^1;
        head=tail=0;
        q[tail++]=0;
        for(int j=1;j<=n;++j){
            while(head+1<tail && GetY(q[head+1],q[head]) <= GetX(q[head+1],q[head])*s[j])++head;
            while(head+1<tail && GetY(j,q[tail-1])*GetX(q[tail-1],q[tail-2]) <= GetY(q[tail-1],q[tail-2])*GetX(j,q[tail-1]))--tail;
            q[tail++]=j;
            int k=q[head];
            dp[index][j]=dp[index^1][k]+(s[j]-s[k+1])*(s[j]-s[k+1]);
        }
    }
    return dp[index][n];
}

int main(){
    int t,num=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i)scanf("%d",s+i);
        sort(s+1,s+1+n);
        printf("Case %d: %d\n",++num,DP());
    }
    return 0;
}

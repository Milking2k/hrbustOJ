
/*������
���ȶ���б��dp���и��ܽ᣺
б��dpһ��Ӧ����������һ�λ򼸶�����ֵ
��1~k,k+1~j,j+1~...�����ֶζ�������������
ֻ�������β����õ�������ά����ֵȻ��
dp[i]=dp[j]+(j+1~i)��ֵ��

���ڱ��⣺
��ĿҪ��m�����������ֵ�����������е�Ԫ�ز�һ����ԭ����������
���Կ϶�����ֱ����б���Ż��������������Է����Ƚ��д�С��������
Ȼ��������m����ֵ���ǿ�������ֵ�ˡ�

���ԣ��ȶ�ԭ������д�С��������
dp[i][j]��ʾ��i��β��j�ε���ֵ
��k+1~i��Ϊһ��
��dp[i][j]=dp[k][j-1]+(s[i]-s[k+1])^2
���ھ�����������kʹ��dp[i][j]��С
����k2<=k1<i
��:dp[k1][j-1]+(s[i]-s[k1+1])^2 <= dp[k2][j-1]+(s[i]-s[k2+1])^2
=>dp[k1][j-1]+s[k1+1]^2 - (dp[k2][j-1]+s[k2+1]^2) / (2s[k1+1]-2s[k2+1]) <= s[i]
����:
y1 = dp[k1][j-1]+s[k1+1]^2
x1 = 2s[k1+1]
y2 = dp[k2][j-1]+s[k2+1]^2
x2 = 2s[k2+1]

=>(y1 - y2)/(x1 - x2) <= i
��������ά����͹����
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

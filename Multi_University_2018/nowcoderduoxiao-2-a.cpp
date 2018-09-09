#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int maxn=100000+7;
LL dp[maxn][2];
int q,k;
LL sum[maxn];
void init()
{
    dp[0][0]=1;dp[0][1]=0;
    for(int i=1;i<maxn;i++){
        if(i-k<0){
            dp[i][0]=1;dp[i][1]=0;
            continue;
        }
        dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
        dp[i][1]=(dp[i-k][0])%MOD;
    }
    sum[0]=0;
    for(int i=1;i<maxn;i++) {
        sum[i]=(sum[i-1]+dp[i][0]+dp[i][1])%MOD;
    }
}
int main()
{
    while(~scanf("%d%d",&q,&k)){
        init();
        for(int i=1;i<=q;i++) {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%lld\n",(sum[r]-sum[l-1]+MOD)%MOD);
        }
    }
    return 0;
}
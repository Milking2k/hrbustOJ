#include <bits/stdc++.h>
using namespace std;

const int maxn=1e4+7;
int a[maxn],b[maxn];
int dp[maxn][10];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        sacnf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=9;j++){
                dp[i][j]=0x3f3f3f3f;
            }
        }
        dp[1][0]=a[1]+2*b[1];///ob ot
        dp[1][1]=2+2*b[1];///db ot
        dp[1][2]=6;///db dt
        dp[1][3]=18+2*b[1];///wb ot
        dp[1][4]=36;///wb wt
        dp[1][5]=45+2*b[1];///mb ot
        dp[1][6]=90;///mb mt
        for(int i=2;i<=n;i++){

        }
    }
    return 0;
}

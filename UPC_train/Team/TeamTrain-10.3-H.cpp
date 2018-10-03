#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
int T,n,m;
int main()
{
    int Cas=0;
    for(scanf("%d",&T);T;T--){
        int ans1[5]={0},ans2[5]={0};
        while(~scanf("%d",&n)&&n){
            if(n%10 == n/10){
                ans1[n%10]++;
                ans1[n/10]++;
            }
            else{
                ans2[n%10]++;
                ans2[n/10]++;
            }
        }
            bool ok = 1;
            int cnt1 = ans1[1];
            int cnt2 = ans2[1];
            rep(i,2,5){
                if(ans1[i]!=cnt1 || ans2[i]!=cnt2){
                    ok = 0;
                }
            }
            if(ok){
                printf("Case #%d: Stroop\n",++Cas);
            }
            else
                printf("Case #%d: Not Stroop\n",++Cas);
    }

    return 0;
}

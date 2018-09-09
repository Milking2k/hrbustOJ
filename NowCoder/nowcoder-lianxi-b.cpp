#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
ll ans[4000007] = {0,0,1,3,6,10,15,21};
void solve()
{
    ll n;
    for(int n=8;n<=4000000;n++){
        ll cnt1 = n/2;
        ll cnt2 = n-cnt1;
        ans[n] = cnt1*cnt2+ans[cnt1]+ans[cnt2];
    }
}
ll lagesolve(ll n)
{
    if(n<=4000000){
        return ans[n];
    }
    ll cnt1 = n/2;
    ll cnt2 = n-cnt1;
//    printf("nowcnt1:%lld nowcnt2:%lld\n",cnt1,cnt2);
    return cnt1*cnt2+lagesolve(cnt1)+lagesolve(cnt2);


//    while(n>10000000){
//        ll cnt1=n/2;
//        ll cnt2=n-cnt1;
//
//    }

}
int main()
{
    solve();
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(n>4000000){
            printf("%lld\n",lagesolve(n));
        }
        else printf("%lld\n",ans[n]);
    }
    return 0;
}

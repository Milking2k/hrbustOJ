#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<b;i++)

typedef long long ll;
int T,n,m;
int main()
{
    while(~scanf("%d%d",&n,&m) && n && m){
        ll ans =0;
        for(int i =2 ;i<=n;i++){
            ans = (ans+m)%i;
        }
        printf("%lld\n",ans+1);
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        ll maxn=0;
        ll min1=0;
        ll sum=0;
        ll x;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x);
            sum+=x;
            maxn=max(maxn,sum);
            min1=min(min1,sum);
        }
        cout<<max(0ll,m-maxn-(-min1)+1ll)<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+7;

int a[maxn];//各个同余系的个数

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=1;i<=k;i++)
        {
            a[i]=n/k;
        }
        int r=n%k;
        for(int i=1;i<=r;i++) a[i]++;
        ll ans=0;

        ans+=(ll)a[k]*(ll)a[k]*(ll)a[k];
        if(k%2==0)
            ans+=(ll)a[k/2]*(ll)a[k/2]*(ll)a[k/2];
        printf("%lld\n",ans);
    }
    return 0;
}
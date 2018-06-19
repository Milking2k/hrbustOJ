#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 207,INF=0x7f7f7f7f;
int a[maxn],f[maxn];
int n;
int t;
int gcd(int a,int b){
    if(a%b) return gcd(b, a%b);
    return b;
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int ans = -INF;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            f[i]=1;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<i;j++)
                if(gcd(a[i],a[j])==1) f[i]=max(f[i],f[j]+1);
        for(int i=1;i<=n;i++)
            ans=max(ans,f[i]);
        printf("%d\n",ans+1);

    }
    return 0;
}

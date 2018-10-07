#include <bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e6+4;
int a[maxn];
int main()
{
    int n,m;
    read(n),read(m);
    for(int i=1;i<=n;i++) {
        read(a[i]);
    }
    sort(a+1,a+1+n);
    int ans=1;
    a[0]=a[1];
    for(int i=1;i<=n;i++) {
        if(a[i]-a[i-1] > m) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

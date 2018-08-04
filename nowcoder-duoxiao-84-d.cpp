#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e5+9;
typedef long long LL;
LL a[maxn];
LL b[maxn];


int main() {
    int T;
    read(T);
    int Cas=1;
    while(T--) {
        int n,m,k;
        read(n);
        read(m);
        read(k);
        memset(a,0,sizeof(a));
        for(int i=1;i<=k;i++) {
            int l,r;
            read(l);
            read(r);
            LL w;
            scanf("%lld",&w);
            a[r]=max(a[r],w);
        }
        LL ans=0;
        for(int i=1;i<=m;i++) {
            ans+=a[i];
        }
        printf("Case #%d: %lld\n",Cas++,ans);

    }
}

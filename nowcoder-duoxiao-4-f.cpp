#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=2005;
char ma[2005][2005];
int vis[2005][2005];
int main() {
    int T;
    read(T);
    while(T--) {
        int n,m;
        read(n);
        read(m);
        memset(ma,0,sizeof(ma));
        int maxl=2;
        if(m&1) maxl=1;
        int maxr=2;
        if(n&1) maxr=1;
        for(int i=1;i<=n;i++) {
            //for(int j=1;j<=m;j++) {
                scanf("%s",ma[i]+1);
                //cin>>ma[i][j];
            //}
            //getchar();
        }
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m/* && j<=(m-maxl)/2*/;j++) {
                if(i>n/2) {
                    if(ma[i][j] != ma[i][m-j+1]) {
                        maxl=max(maxl,(m-2*(j-1)));
                        //cout<<i<<" "<<j<<" "<<ma[i][j]<<" "<<ma[i][m-j+1]<<endl;
                    }
                    continue;
                }
                if(ma[i][j] != ma[i][m-j+1]) {
                    maxl=max(maxl,(m-2*(j-1)));
                    //cout<<i<<" "<<j<<endl;
                }
                if(ma[i][j] != ma[n-i+1][j] ) {
                    maxr=max(maxr,(n-(2*(i-1))));
                    //cout<<i<<" "<<j<<endl;
                }
            }
        }
        //cout<<maxl<<" "<<maxr<<endl;
        long long ans=((m-maxl)/2)*((n-maxr)/2);
        ans=max(ans,0LL);
        printf("%lld\n",ans);
    }
}

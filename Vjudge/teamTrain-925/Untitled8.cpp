#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e4+3;
int n,a1,a2,a3;
int vis[maxn];

int main() {
    int T;
    read(T);
    while(T--) {
        memset(vis,0,sizeof(vis));
        int F=1;
        read(n);
        read(a1);
        read(a2);
        read(a3);
        for(int i=1;i<=a1;i++) {
            int x;
            read(x);
            vis[x]=1;
        }
        for(int i=1;i<=a2;i++) {
            int x;
            read(x);
            int cnt=0;
            int idx;
            for(int j=1;j<=x;j++) {
                int z;
                read(z);
                if(vis[z]==0)idx=z;
                cnt+=vis[z];
            }
            if(cnt==x-1) {
                vis[idx]=-1;
            }
            if(cnt==x) {
                F=0;
//                puts("&^%");
            }
        }
        for(int i=1;i<=a3;i++) {
            int x;
            read(x);
            int cnt=0;
            int ff=0;
            for(int j=1;j<=x;j++) {
                int z;
                read(z);
                if(vis[z]==1) {
                    cnt++;
                }
                if(vis[z]==-1) {
                    ff+=1;
                }
            }
//            if(ff)continue;
            int f;
            read(f);
//            cout<<ff<<" "<<vis[f]<<endl;
            if(cnt==x) {
//                vis[f]=1;
                if(vis[f]==-1) {
                    F=0;
//                    puts("ASD");
                }
                if(vis[f]==0) {
                    vis[f]=1;
                }
            }
            if(ff+cnt==x && ff && vis[f]==1) {
                F=0;
//                puts("$%^");
            }
        }
        if(F)puts("YES");
        else puts("NO");
    }
}

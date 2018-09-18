#include <bits/stdc++.h>
using namespace std;

const int maxn=1024*4;
int vis[maxn];
int a[105];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=0;i<maxn;i++){
            vis[i]=0;
        }
        for(int i=1;i<=n;i++){
            int as=0,len=1;
            for(int j=i;j<=n;j++){
                as^=a[j];
                len++;
                if(!vis[as])vis[as]=len;
                if(vis[as]<len)vis[as]=len;
            }
        }
        int q;
        scanf("%d",&q);
        while(q--){
            int x;
            scanf("%d",&x);
            int ans=0;
            for(int i=0;i<=maxn;i++){
                if(x-i>=0)ans=max(ans,vis[x-i]);
                if(x+i<maxn)ans=max(ans,vis[x+i]);
                if(ans!=0)break;
            }
            printf("%d\n",ans-1);
        }
        puts("");
    }
    return 0;
}

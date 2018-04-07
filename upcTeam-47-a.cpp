#include <bits/stdc++.h>
using namespace std;
int mp[1005][1005];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        memset(mp,0,sizeof(mp));
        int n,m,a,b;
        scanf("%d%d%d%d",&n,&m,&a,&b);
        int cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&mp[i][j]);
                if(a<=mp[i][j]&&mp[i][j]<=b)cnt=cnt;
                else cnt++;
            }
        }
        if(a>b)puts("No Solution");
        else printf("%d\n",cnt);
    }
    return 0;
}
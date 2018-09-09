#include<bits/stdc++.h>
using namespace std;

int t,n,m;
int emt[207];
int vis[207];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++){
        scanf("%d",&emt[i]);
    }

    int ans = 0;
    for(int i=1;i<=2*n;i++){
        if(!vis[i])
        for(int j=i+1; j<=2*n; j++){
            if(emt[i] == emt[j]){
                vis[i] = vis[j] = 1;
                break;
            }
            ans += vis[j]? 0:1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
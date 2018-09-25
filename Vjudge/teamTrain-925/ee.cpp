#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
const int N = 1e3+7;
int T,n,m;
int a[N];
ll sum=0;
bool vis[N];
void dfs(int pos){
    if(vis[pos]){
        sum++;
        return ;
    }
    vis[pos]=1;
    dfs(a[pos]);
}
int main()
{
    for(scanf("%d",&T);T;T--){
        sum=0;
        scanf("%d",&n);
        rep(i,1,n+1){
            scanf("%d",a+i);
        }
        memset(vis,0,sizeof(vis));
        rep(i,1,n+1){
            if(!vis[a[i]]){
                dfs(a[i]);
            }
        }
        printf("%lld\n",sum);
    }

    return 0;
}

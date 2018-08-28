#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=200000;
const int Mod=1e9+7;
ll sum[maxn+5],dp[maxn+5];
ll biao[maxn+5] ;
void Init()
{
    biao[0] = biao[1] = 1 ;
    for(int i = 2 ; i<=maxn ; ++i)
    {
        biao[i] = biao[i-1]*i%Mod;
        biao[i] %= Mod ;
    }
}
int n;
class node
{
    public :
    int to,w;
    node(int _to,int _w):to(_to),w(_w){};
};
vector<node>edge[maxn];
void dfs(int root,int father)
{
    sum[root]=1;
    for(int i=0; i<edge[root].size(); i++)
    {
        int son=edge[root][i].to;
        int len=edge[root][i].w;
        if(son==father) continue;
        printf("son:%d root:%d\n",son,root);
        dfs(son,root);
        sum[root]=(sum[root]+sum[son])%Mod;
        dp[root]=(dp[root]+(dp[son]+(sum[son]*((n-sum[son]+Mod)%Mod)%Mod)*len%Mod)%Mod)%Mod;
    }
}
int main()
{
    Init() ;
    while(~scanf("%d",&n))
    {
        if(n==1)
        {
            printf("0\n");
        }
        else
        {
            for(int i=0; i<=n; i++) edge[i].clear();
            for(int i=1; i<n; i++)
            {
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                edge[a-1].push_back(node(b-1,c));
                edge[b-1].push_back(node(a-1,c));
            }
            memset(dp,0,sizeof(dp));
            memset(sum,0,sizeof(sum));
            dfs(0,-1);
            ll aa=biao[n-2]*2*(n-1)%Mod;
            ll ans=aa*dp[0]%Mod;
            printf("%lld\n",ans);
        }

    }

}
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=102;
int mp[maxn][maxn],n,m;
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(mp,0,sizeof(mp));
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            mp[a][b]=1;
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    if(mp[i][k]&&mp[k][j])
                        mp[i][j]=1;
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            int res=n-1;
            for(int j=1; j<=n; j++)
                if(mp[i][j]||mp[j][i])
                    res--;
            if(!res)ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}


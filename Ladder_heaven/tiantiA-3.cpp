/*
查询是否存在，不存在入队，满队出头到，求入队多少次
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f

int n,m;
int emt[1005];
int vis[1005];
int cnt;
int ans;
int l,r;
int main(int argc, char const *argv[])
{
	// freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&m,&n))
    {
        memset(emt,0,sizeof(emt));
        memset(vis,0,sizeof(vis));
        ans=0;
        l=r=0;
		for (int i = 1; i <= n; ++i)
        {
            scanf("%d",&cnt);
             if (emt[cnt]==0)
             {
                ans++;
                r++;vis[r]=cnt;emt[cnt]=1;
                if (r>m) {l++;emt[vis[l]]=0;}
             }
        }
        printf("%d\n", ans);
	}
	return 0;
}
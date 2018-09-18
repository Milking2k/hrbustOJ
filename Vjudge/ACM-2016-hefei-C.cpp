#include<bits/stdc++.h>
using namespace std;
const int maxn = 40005;
vector<pair<int,int> >e[maxn];
 
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 0;i<=n;i++)e[i].clear();
		for(int i = 0;i<n-1;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(make_pair(v,w));
			e[v].push_back(make_pair(u,w));
		}
		for(int i = 1;i<=m;i++)
		{
			int op;
			scanf("%d",&op);
			if(op==0)
			{
                int r;
				scanf("%d",&r);
				int ans = 0;
				for(int i = 0;i<e[r].size();i++)
				{
					ans+=e[r][i].second;
				}
				if(ans&1)
					printf("Girls win!\n");
				else printf("Boys win!\n");
			}
			else
			{
				int x,y,z;
				scanf("%d%d%d",&x,&y,&z);
				for(int i=0;i<e[x].size();i++)
				{
					if(y==e[x][i].first)
						e[x][i].second = z;
				}
				for(int i = 0;i<e[y].size();i++)
				{
					if(x==e[y][i].first)
						e[y][i].second = z;
				}
			}
		}
	}
}

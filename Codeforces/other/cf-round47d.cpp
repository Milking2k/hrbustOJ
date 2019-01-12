// 问能否建立一个连通图，这个连通图的所有边的两端点互质，n个点m条边

#include <bits/stdc++.h>
using namespace std;
int t,n,m;
struct node
{
	int x,y;
}emt[100007];
int main()
{
	scanf("%d%d",&n,&m);
	int len = m; // 需要加的边数
	for (int i = 1; i <= n && len; ++i)
	{
		for (int j = i+1; j <= n && len; ++j)
		{
			if (__gcd(i,j)==1)
			{
				len--;
				emt[len] = (node){i,j};
			}
		}
	}
	if(len || n>m+1){
		return !printf("Impossible\n");
	}

	printf("Possible\n");
	for (int i = 0; i < m; ++i)
	{
		printf("%d %d\n", emt[i].x,emt[i].y);
	}
	return 0;
}
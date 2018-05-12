#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int n,m;

int par[10007];
int rankH[10007];

void init(int n)
{
	for (int i = 0; i < n; ++i)
	{
		par[i]=i;
		rankH[i]=0;
	}
}

int find(int x)
{
	if(par[x]==x) return x;
	else return par[x] = find(par[x]);
}

void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x==y) return ;
	if(rankH[x] < rankH[y]) par[x] = y;
	else{
		par[y]=x;
		if(rankH[x] == rankH[y]) rankH[x]++;
	}
}

bool same(int x,int y)
{
	return find(x) == find(y);
}

int main(int argc, char const *argv[])
{
	while(~scanf("%d%d",&n,&m))
	{
		init(n);
		for (int i = 0; i < m; ++i)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			unite(b,a);
		}

		printf("\n");
		for (int i = 0; i < n; ++i)
		{
			printf("%d ", par[i]);
		}
		printf("\n");
	}
	return 0;
}
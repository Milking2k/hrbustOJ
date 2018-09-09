#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int book[100005];
std::vector<int> e[100005];
int link[100005];
int n,m;

int find(int v)
{
	for (int i = 0; i < m; ++i)
	{
		if(book[i]==0 && e[v][i])
		{
			book[i] = 1;
			if(link[i] == -1 || find(link[i]))
			{
				link[i] = v;
				return 1;
			}
		}
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i)
	{
		int x,y;
		scanf("%d%d", x,y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	memset(link,-1,sizeof(link));
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		memset(book,0,sizeof(book));
		if (find(i))
		{
			ans++;
		}
	}
	printf("%d\n", ans);

	return 0;
}
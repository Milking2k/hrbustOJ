// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int e[305][305];
int book[305];
int match[305];
int p,n;
int t;
int num;
int sum=0;
int hasNoPatr=0;
bool dfs(int x)
{
	for (int i = 1; i <= n; ++i)
	{
		if(e[x][i] && book[i] == 0)
		{
			book[i]=1;
			if( match[i]==-1 || dfs(match[i]) )
			{
				match[i] = x;
				return 1;
			}
		}
	}
	return 0;
}


int main(int argc, char const *argv[])
{
	scanf("%d",&t);
	while(t--)
	{
		memset(e,0,sizeof(e));
		sum=0;
		hasNoPatr=0;
		scanf("%d%d",&p,&n);
		for (int i = 1; i <= p; ++i)
		{
			scanf("%d",&num);
			if(num==0) hasNoPatr=1;
			for (int j = num; j >= 1; --j)
			{
				int v;
				scanf("%d", &v);
				e[i][v]=1;
			}
		}

		if(hasNoPatr){puts("NO");continue;}
		memset(match,-1,sizeof(match));

		for (int i = 1; i <= p; ++i)
		{
			memset(book,0,sizeof(book));
			if(dfs(i)) sum++;
		}
		if(sum==p)puts("YES");
		else puts("NO");
	}

	return 0;
}	
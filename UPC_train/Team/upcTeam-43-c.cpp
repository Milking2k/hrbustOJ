#include <bits/stdc++.h>
using namespace std;

// int cnt=0;
// int hasEdge[2005][2005];
std::vector<int> hasEdge[2005];
// int book[2005];
int n,k;
int ans,sum;

void dfs(int goal, int root, int len)
{
	if(len <= k/2) ans++;
	if(len == k/2+1) sum++;
	for(auto i:hasEdge[goal]) 	
		if(i!=root) dfs(i,goal,len+1);
}

int main(int argc, char const *argv[])
{
	memset(hasEdge,0,sizeof(hasEdge));
	cin >> n >> k;
	for (int i = 1; i < n; ++i)
	{
		int x,y;
		cin >> x >> y;
		hasEdge[x].push_back(y);
		hasEdge[y].push_back(x);
	}
	int maxans=0;	
	for (int i = 1; i <=  n; ++i)
	{
		ans = 1;
		int maxsum = 0;
		for(auto j:hasEdge[i])
		{
			sum=0;
			dfs(j,i,1);
			if(k&1) maxsum=max(maxsum, sum);
		}
		maxans = max(maxans, ans+maxsum);
	}
	printf("%d\n", n-maxans);
	
	return 0;
}
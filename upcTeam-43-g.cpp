#include <bits/stdc++.h>
using namespace std;

bool book[100005];
int ballNum[100005];
int main(int argc, char const *argv[])
{
	int n,m;

	cin >> n >> m;
	// memset(ballNum,1,sizeof(ballNum));
	memset(book,0,sizeof(book));
	fill(ballNum+1, ballNum+n+1, 1);// 初始化为其他值只能用fill！！！！！！
	book[1]=1;

	for (int i = 0; i < m; ++i)
	{
		int x,y;
		cin >> x >> y;
		if(book[x]) 
			book[y] = 1;

		--ballNum[x];
		++ballNum[y];

		if(ballNum[x]==0) 
			book[x] = 0;
	}
	int ans=0;
	for (int i = 1; i <= n; ++i)
	{
		ans += book[i];
	}
	printf("%d\n", ans);
	return 0;
}
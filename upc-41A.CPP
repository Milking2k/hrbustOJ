#include <bits/stdc++.h>
using namespace std;
int dp[31][31];
int dir[2][2] = {
	{0,1},
	{1,0}
};

int e[55][55];
int len[3000]={0};
int countLen = 0;
int n,m;
int max1=0,max2=0;
int cnt=0;
void dfs(int col,int row)
{
		printf("nextCol:%d nextRow:%d \n", col,row);

	if(e[col][row]==0){

		if(cnt > max1) max1 = cnt;
		else if(cnt > max2) max2 = cnt;
		printf("\n%d %d \n", max1,max2);
		
		countLen++;
		return;
	}
	for (int i = 0; i < 2; ++i)
	{
		int cntCol = col+dir[i][0];
		int cntRow = row+dir[i][1];
		if(cntCol < n && cntRow < m)
		{
			cnt += e[cntCol][cntRow];
			//printf("%d  xxx\n", e[col][row]);

			dfs(cntCol,cntRow);
		}
	}
	return;
}
bool cmp(int a,int b){return a>b;}
int main(int argc, char const *argv[])
{
	cin >> n >> m;
	memset(e,-1,sizeof(e));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> e[i][j];
		}
	}
	
	e[0][0] = -1;
	dfs(0,0);

	printf("\n%d %d \n", max1,max2);
	return 0;
}
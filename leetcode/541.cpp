#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+7;

int main()
{
	vector< vector<int> > matrix;
	int n,m; // n row, m col;
	// scanf

	const int N = n;
	const int M = m; 
	int ans[N][M];

	for (int i=0;i<n;++i) {
		for (int j=0;j<m;++j) {
			if(matrix[i][j] == 0) {
				ans[i][j] = 0;
				continue;
}
			
if(i==0 && j==0){
				ans[i][j] = INF;
}
			else if(i==0) {
				ans[i][j] = ans[i][j-1] +1;
			}
			else if(j==0) {
				ans[i][j] = ans[i-1][j] + 1;
			}			
			else{ // i!=0&&j!=0;
				ans[i][j] = min(ans[i-1][j]+1, ans[i][j-1]);
			}
		}
	}

	for (int i=n-1;i>=0;--i) {
		for (int j=m-1;j>=0;--j) {
			if(matrix[i][j] == 0) {
				ans[i][j] = 0;
				continue;
}
			
if(i==n-1&& j==m-1){
				ans[i][j] = INF;
}
			else if(i==n-1) {
				ans[i][j] = ans[i][j+1] +1;
			}
			else if(j==m-1) {
				ans[i][j] = ans[i+1][j] + 1;
			}
			else{ // i!=0&&j!=0;
				ans[i][j] = min(ans[i+1][j]+1, ans[i][j+1]);
			}
		}
	}
	return 0; 
}

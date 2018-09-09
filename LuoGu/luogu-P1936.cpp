// ①m、n∈{1,2，……，k} ②（n²-m*n-m²）²=1 ③m、n为整数
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	// int n=10000;
	// int m=10000;
	// for (int i = 1; i < n; ++i)
	// {
	// 	for (int j = 1; j < m; ++j)
	// 	{
	// 		if(i*i-i*j-j*j == 1 || i*i-i*j-j*j == -1)
	// 		printf("i:%d j:%d\n", i,j);
	// 	}
	// }
	int k;
	cin >> k;
	int n=1,m=1;
	for (int i = 0; i < n; ++i)
	{
		if(n+m<=k&&n<=k)
		{
			int t = m;
			m = n;
			n = t+n;
		}
	}
	printf("m=%d\n", m);
	printf("n=%d\n", n);
	return 0;
}
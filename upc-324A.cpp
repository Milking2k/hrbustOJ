#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int a[40][40];
	memset(a,0,sizeof(a));
	cin >> n;
	a[0][n/2] = 1;
	int i = 0;
	int j = n/2;
	int count = 1;
	// int num =
	while(count != n*n)
	{
		// printf("i:%d  j:%d\n", i,j);
		if (i==0 && j!=n-1)
		{
			i = n-1;
			j = j+1;
			a[i][j] = ++count;
		}else if(j==n-1 && i!=0)
		{
			j = 0;
			i = i-1;
			a[i][j] = ++count;
		}else if (i==0 && j==n-1)
		{
			i = 1;
			a[i][j] = ++count;
		}else if (i != 0 && j!= n-1 && a[i-1][j+1] == 0)
		{
			i = i-1;
			j = j+1;
			a[i][j] = ++count;
		}else{
			// printf("else:i:%d  j:%d\n", i,j);
			i++;
			a[i][j] = ++count;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			j==0? printf("%d", a[i][j]) : printf(" %d", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
// int n,m;
// int foo(const int a[],const int b[])
// {
// 	int max = 
// }
int main(int argc, char const *argv[])
{
	int n,m;
	while(cin>>n>>m)
	{
		int a[10003];
		int b[10003];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		sort(a,a+n);
		// printf("%d %d\n", a[0],a[1]);
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}
		sort(b,b+n);
		// foo(a,b);
		int minlen = min(n,m);
		int i,j;
		int first=1;
		for (i = 0,j = 0; i < n && j < m;)
		{
			if (a[i] < b[j])
			{
				if (first)
				{
					printf("%d", a[i]);
					i++;
					first=0;
					continue;
				}
				printf(" %d", a[i]);
				i++;
			}else if(a[i] == b[j])
			{
				if (first)
				{
					printf("%d", a[i]);
					i++;
					first=0;
					j++;
					continue;
				}
				printf(" %d", a[i]);
				i++;
				j++;
			}
			else{
				if (first)
				{
					printf("%d", b[j]);
					j++;
					first=0;
					continue;
				}
				printf(" %d", b[j]);
				j++;
			}
		}
		// printf("i:%d   j:%d\n",  i,j);

		if (i==n)
		{
			for (int k = j; k < m; ++k)
			{
				if (k==j && first)
				{
					printf("%d", b[k]);
				}else{
					printf(" %d", b[k]);
				}
			}
			printf("\n");
		}
		else if (j==m)
		{
			for (int k = i; k < n; ++k)
			{
				if (k==i && first)
				{
					printf("%d", a[k]);
				}else{
					printf(" %d", a[k]);
				}
			}
			printf("\n");
		}
		

	}
	return 0;
}
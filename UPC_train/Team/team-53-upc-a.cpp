#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val,cnt;
}a[1007];
int n;

bool cmp(node a, node b)
{
	return a.val > b.val;
}

int main()
{
	
	while(~scanf("%d",&n))
	{
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i].val);
		}
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&a[i].cnt);
		}
		sort(a,a+n);
		long long int ans=0;
		

	}

	return 0;
}
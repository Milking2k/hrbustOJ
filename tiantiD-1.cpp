#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)

struct node
{
	int x,val;
}emt[20005];

int n,k;
int emtInrc[15];
// int emt[20005];

bool cmp(node a,node b)
{
	if(a.val==b.val) return a.x<b.x;
	else return a.val > b.val;
}

int main(int argc, char const *argv[])
{
	while(~rdd(n,k))
	{
		for(int i=0;i<10;i++) rd(emtInrc[i]);
		for (int i = 0; i < n; ++i)
		{
			rd(emt[i].val);
			emt[i].x = i;
		}
		sort(emt,emt+n,cmp);
		for (int i = 0; i < n; ++i)
		{
			// rd(emt[i].val);
			// emt[i].x = i;
			emt[i].val += emtInrc[i%10];
			// printf("%d:%d", i,emt[i].val);
			// i==n-1?printf("\n"):printf(" ");
		}
		sort(emt,emt+n,cmp);
		for (int i = 0; i < k; ++i)
		{
			printf("%d", emt[i].x+1);
			i==k-1?printf("\n"):printf(" ");
		}


	}

	
	return 0;
}
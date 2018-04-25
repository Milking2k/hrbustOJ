#include <bits/stdc++.h>
using namespace std;
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)
#define rddd(x,y,k) scanf("%d%d%d",&x,&y,&k)
#define ll long long int

struct node
{
	int x,y,val;
}emt[405];

int n,m,k;
bool cmp(node a,node b){return a.val>b.val;}

int main(int argc, char const *argv[])
{
	while(~rddd(n,m,k))
	{
		int top=0;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				int cnt;
				rd(cnt);
				if(cnt!=0)
				{
					emt[top].x = j;
					emt[top].y = i;
					emt[top++].val = cnt;
				}
			}
		}

		sort(emt,emt+top,cmp);
		int sumbf[400]={0};
		sumbf[0]=1;
		for (int i = 1; i < top; ++i)
		{
			sumbf[i] = 1 + sumbf[i-1] + abs(emt[i].x-emt[i-1].x) + abs(emt[i].y-emt[i-1].y); 
			// printf("%d  ", sumbf[i]);
		}
		// printf("\n");
		int ans=0;
		k = k-emt[0].y;
		// int cnt;
		int i;
		for (i = 0; sumbf[i] + emt[i].y+1 < k; ++i)
		{
			// cnt = sumbf[i];
			// printf("cnt:%d\n", sumbf[i] + emt[i].y+1);
			ans+=emt[i].val;
		}
		printf("%d\n", ans);



	}
	
	return 0;
}
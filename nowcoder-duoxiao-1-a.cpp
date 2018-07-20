#include <bits/stdc++.h>
using namespace std;

int n,q;
int emt[100007];
int tole[100007][2];
int main(int argc, char const *argv[])
{
	while(~scanf("%d%d",&n,&q)){
		memset(tole,0,sizeof(tole));
		int sumnum=0;
		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&emt[i]);
			if(tole[emt[i]][0]==0){
				tole[emt[i]][0] = i;
				tole[emt[i]][1] = i;
				sumnum++;
			}
			else{
				tole[emt[i]][1] = i;
			}
		}


		int l,r,ans=0;
		for (int i = 0; i < q; ++i)
		{
			scanf("%d%d",&l,&r);

			if(l>=r+1){
				printf("%d\n", sumnum);
				continue;
			}
			for (int j = l+1; j < r; ++j)
			{
				if(tole[emt[j]][0]==j && tole[emt[j]][1] < r){
					ans++;
				}
			}
			printf("%d\n", sumnum-ans);
		}
	}
	return 0;
}

/*
3 2
1 2 1
1 2
1 3
*/
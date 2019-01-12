// 用钱包walt买价值emt的物品，顺序用钱，不找回，最多购买

#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m,emt[1007],walt[1007];
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; ++i) {
		scanf("%d",&emt[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d",&walt[i]);
	}

	int ans=0,j=0;// to the walt
	for (int i = 0; i < n; ++i)
	{
		if(walt[j] >= emt[i]){
			ans++;
			j++;
		}
	}

	printf("%d\n", ans);

	return 0;
}
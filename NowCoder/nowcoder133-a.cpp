#include <bits/stdc++.h>
using namespace std;
int n,emt[100007],vals[1000007][2];
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&emt[i]);
		sum += emt[i];
	}

	sort(emt+1,emt+1+n);

	int j=0;
	int maxnum=0;
	int maxpos=0;
	for(int i=n;i>=1;i--) {// j from 1 to n
		int a,b;
		if(i!=1)
			scanf("%d%d",&a,&b);
		if(vals[j][0]==emt[i]){
			vals[j][1]++;
		}
		else {
			j++;
			vals[j][0] = emt[i];
			vals[j][1] = 1;
		}
	}

	long long minnum=0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= j; ++i)
	{
		minnum  = min(sum+(n-2*vals[i][1])*vals[i][0],minnum);
	}

	printf("%lld\n", minnum);



	return 0;
}
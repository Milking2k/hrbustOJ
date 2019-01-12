// 每次对一个序列输入x,d；每个数都+x,选择一个点j，向外扩散增加d，分别加到对应的位置上
// 问最大的平均数是多少

#include <iostream>
#include <cstdio>
using namespace std;
long long t,n,m,ans=0;
int main(int argc, char const *argv[])
{
	scanf("%d%d",&n,&m);
	for (int i = 0; i < m; ++i)
	{
		int x,d;
		scanf("%d%d",&x,&d);
		if(d>0) ans += n*x + d*(n-1)*n/2;
		else ans += n*x + d*(n-(n+1)/2)*((n+1)/2);
	}
	printf("%.15f\n", 1.0*ans/n);
	return 0;
}
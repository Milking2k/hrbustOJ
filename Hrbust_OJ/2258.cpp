#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int p,n;
	while(~scanf("%d%d",&p,&n))
	{
		int maxNum = (n%1152==0 ? n/1152 : n/1152+1);
		int minNum = (n%576==0 ? n/576 : n/576+1);
		printf("%d ",maxNum);
		if (p != 100)
			printf("%d\n",minNum);
		else
			printf("%d\n",maxNum);
	}
	return 0;
}
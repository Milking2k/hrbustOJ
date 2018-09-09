#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int x1,y1,x2,y2,x3,y3;
	while(~scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3))
	{
		if ((y1-y3)*(x1-x2) == (y1-y2)*(x1-x3))
		{
			printf("JiaoZhuV5!\n");
		}else{
			printf("Orz!\n");
		}
	}
	return 0;
}
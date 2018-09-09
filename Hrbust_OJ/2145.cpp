#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int a1,b1,a2,b2,c;
		scanf("%d%d%d%d%d",&a1,&b1,&a2,&b2,&c);
		printf("%d\n", (a2*b2*(b1-b2) - b2*(a1*b1-a2*b2)) / (c*(b1-b2) - a1*b1 + a2*b2));
	}
	
	return 0;
}
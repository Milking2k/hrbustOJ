#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		if ((a<=b && a>=c) || (b<=a && a<=c))
			printf("%d\n", a);
		else if ((a<=b && b<=c) || (c<=b && b<=a))
			printf("%d\n", b);
		else if ((b<=c && c<=a) || (a<=c && c<=b))
			printf("%d\n", c);
	}
	return 0;
}

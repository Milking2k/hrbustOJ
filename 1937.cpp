#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int foo(int n, int k)
{
	int m = k;
	while(k<=n)
	{
		k=k*m;
	}
	return k/m;
}
int main(int argc, char const *argv[])
{
	char a[33];
	int n,k;
	while(~scanf("%d%d", &n,&k))
	{
		int isFu = 0;
		memset(a,-1,sizeof(a));
		a[0] = 48;
		if (n<0){
			n = -1*n;
			isFu = 1;
		}
		int max = foo(n,k);
		// printf("max=%d\n", max);
		// printf("0%1=%d\n", (0%1));
		for (int i = 0; (n!=0 || max!=0) ; ++i)
		{
			switch(n/max)
			{
				case 10:a[i]='A';break;
				case 11:a[i]='B';break;
				case 12:a[i]='C';break;
				case 13:a[i]='D';break;
				case 14:a[i]='E';break;
				case 15:a[i]='F';break;
				default:a[i]=(n/max + 48);break;
			}
			n   %= max;
			max /= k;
			// printf("n=%d max=%d\n", n,max);
		}
		if (isFu)
			printf("-");
		for (int i = 0; a[i] != -1; ++i)
		{
			printf("%c", a[i]);	
		}
		printf("\n");
	}
	return 0;
}
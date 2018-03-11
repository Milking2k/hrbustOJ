#include <cstdio>
int main(int argc, char const *argv[])
{
	int x=1,y=1,n;
	while(scanf("%d",&n) != EOF)
	{
		if (n<=2)
		{
			printf("1\n");
			continue;
		}
		int sum=2;
		x=y=1;
		while(sum<n)
		{
			int t;
			sum++;
			t = y;
			y = x + y;
			x = t;
			// printf("sum=%d n=%d y=%d\n", sum,n,y);
		}
		printf("%d\n", y);
		// printf("%d\n", sum+2);
	}
	return 0;
}
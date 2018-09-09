#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	int t=0;
	while(cin >> n)
	{
		t=0;
		if (n==1 || n==2 || n==3)
		{
			printf("1\n");
			continue;
		}

		// if (n%2 == 1)
		// {
		// 	printf("%d\n", (n-1)/2);
		// 	continue;
		// }
		// else{
		// 	printf("%d\n", n/2);
		// }

		while(n != 2 && n != 3 && n!=1)
		{
			t += n/3;
			n = n/3+n%3;
			
		}
		if (n==2 || n==3)
		{
			t++;
		}
		printf("%d\n", t);

	}
	
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
int foo(long long int a,long long int b)
{
	if (0 == a%b)
	{
		return b;
	}
	return foo(b,a%b);
}
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int a,b;
		cin >> a >> b;
		// printf("%d\n", foo(a,b));
		if (foo(a,b) != 1)
		{
			printf("Sim\n");
		}else{
			printf("Nao\n");
		}
	}
	return 0;
}
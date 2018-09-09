#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
	if(a%b == 0) return b;
	return gcd(b,a%b);
}

int lcm(int a, int b)
{
	return a*b/gcd(a,b);
}

int main(int argc, char const *argv[])
{
	int a,b;
	while(cin >> a >> b)
	{
		printf("%d\n", lcm(a,b));
	}
	return 0;
}
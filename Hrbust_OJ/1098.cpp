#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--)
	{
		float a,b;
		cin >> a >> b;
		printf("%.4f\n", a/b);
	}
	return 0;
}
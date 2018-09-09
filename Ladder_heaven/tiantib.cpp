#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	// char c;
	string s;
	while(~scanf("%d\n", &n))
	{
		getline(cin ,s);
		// printf("%d\n", n-pos > 0? pos : n-pos);
		printf("%d\n", n/2 + n%2);
	}
	return 0;
}

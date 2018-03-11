#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		string s;
		getline(cin, s);
		if (s[0] == s[2])
		{
			printf("6\n");
		}else if (s[0] != s[2])
		{
			printf("5\n");
		}
	}
}
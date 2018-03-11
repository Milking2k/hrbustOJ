#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		if (s[0] != '\n')
		{
			printf("%d\n", s.length());
		}
	}
	return 0;
}
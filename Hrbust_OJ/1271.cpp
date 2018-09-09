#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin, s))
	{
		for (unsigned int i = 0; i < s.length(); ++i)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
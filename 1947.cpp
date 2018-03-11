#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin, s))
	{
		int n=0;
		for (unsigned int i = 0; i < s.length() && s[i] != 'B'; ++i)
		{
			if ('(' == s[i])
			{
				n++;
			}else if (')' == s[i])
			{
				n--;
			}
		}
		printf("%d\n", n);
	}
	return 0;
}
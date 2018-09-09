#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin, s))
	{
		char first = s[0];
		int putNum=0;
		for (unsigned int i = 0; i <= s.length(); ++i)
		{
			if (s[i] == first)
			{
				// ans[(int)s[i] - 'A']++;
				putNum++;
			}else{
				// printf("%c%d", s[i-1], ans[(int)s[i-1] - 'A']);
				printf("%c%d", s[i-1], putNum);
				first = s[i];
				putNum = 1;
				// putNum++;
			}

		}
		printf("\n");
	}
	return 0;
}
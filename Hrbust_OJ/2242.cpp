#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	char gole[10] = {'m','a','r','s','h','t','o','m','p'};
	while(getline(cin,s))
	{
		int j;
		for (unsigned int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'm' || s[i] == 'M')
			{
				int next = 0;
				for (j = 0; j < 9; ++j)
				{
					char lowS = s[j+i];
					if (tolower(lowS) != gole[j])
					{
						next = 1;
					}
				}
				if (!next)
				{
					printf("fjxmlhx");
					i = i+8;
					continue;
				}
			}
			printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}
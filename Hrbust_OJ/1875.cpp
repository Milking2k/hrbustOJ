#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		int canEndl = 0;
		unsigned int i,j;
		if (s[0] == '\0') continue;
		for (i = 0; i <= s.length(); ++i)
		{
			if (48 <= (int)s[i] && (int)s[i] <= 57)
			{
				for (j = i; (48 <= (int)s[j] && (int)s[j] <= 57) ; ++j);
				if(canEndl)	printf("\n");
				i = j;
			}
			if(i < s.length())
				printf("%c", s[i]);
			if ((int)s[i] > 57) canEndl = 1;
			else if (i==s.length() && !(48 <= (int)s[i-1] && (int)s[i-1] <= 57))
			{
				printf("\n");
			}
		}

	}
	return 0;
}
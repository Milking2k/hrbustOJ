#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
int main()
{
	string s;
	while(getline(cin, s))
	{
		int a=0,b=0,c=0;
		for (unsigned int i = 0; i < s.length(); ++i)
		{
			if (islower(s[i]))
			{
				a++;	
			}	
			else if (isupper(s[i]))
			{
				b++;
			}else if (isspace(s[i]))
			{
				c++;
			}
		}
		printf("%d %d %d\n", a,b,c);
	}
}
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
// char a[17] = {'1','2','3'}
int main(int argc, char const *argv[])
{
	int m;
	while(~scanf("%d", &m))
	{
		getchar();
		string s;
		getline(cin, s);
		int sum = 0;
		int bog = 1;
		// printf("%d\n", s.length());
		for (int i = s.length() -1 ; i >= 0; --i)
		{
			// printf("%c\n", s[i]);
			switch(tolower(s[i]))
			{
				case 'a': sum += 10*bog;break;
				case 'b': sum += 11*bog;break;
				case 'c': sum += 12*bog;break;
				case 'd': sum += 13*bog;break;
				case 'e': sum += 14*bog;break;
				case 'f': sum += 15*bog;break;
				default: sum += ((int)s[i] - 48)*bog;break;
			}
			bog *= m;
		}
		printf("%d\n", sum);
	}
	return 0;
}
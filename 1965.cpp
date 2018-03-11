#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	string s;
	int a[30];
	while(getline(cin,s))
	{
		memset(a,0,sizeof(a));
		for (unsigned int i = 0; i < s.length(); ++i)
		{
			if ( a[ ((int)s[i]-97) ] )
			{
				printf("no\n");
				break;
			}
			a[ ((int)s[i]-97) ] = 1;
			if (i==s.length()-1)
			{
				printf("yes\n");
			}
		}

	}
	// printf("%d\n", 'a');
	return 0;
}

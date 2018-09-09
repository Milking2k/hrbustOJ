#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		char s[10001];
		memset(s,1,sizeof(s));
		int tmp=0;
		gets(s);
		for (int i = 0;( isalpha(s[i]) || isspace(s[i])); ++i)
		{
			// printf("s[i] = %c_\n", s[i]);
			if (s[i] != ' ')
			{
				tmp++;
				while(isalpha(s[i])){
					// printf("s[i]=%c_\n", s[i]);
					i++;
				}
			}

		}
		printf("%d\n", tmp);
	}

	return 0;
}
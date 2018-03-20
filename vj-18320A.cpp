#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin,s))
	{
		if (s.length() % 2 != 0)
		{
			printf("NO\n");
			continue;
		}
		int nothis=0;
		for (int i = 0; i < s.length()/2; ++i)
		{
			if (s[i] != s[s.length()/2+i])
			{
				printf("NO\n");
				nothis=1;
				break;
			}
		}
		if (!nothis)
		{
			printf("YES\n");
		}
	}
	return 0;
}
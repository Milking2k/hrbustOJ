#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	int caseNum=0;
	while(getline(cin, s))
	{
		int i;
		if (s[0] == 'S' && s[1] == 'T' && s[2] == 'O' && s[3] == 'P')
		{
			break;
		}
		for (i = 0; i < (s.length()-1)/2 + 1; ++i)
		{
			if (s[i] != s[s.length()-i-1])
			{
				break;
			}
		}
		if (i == (s.length()-1)/2 + 1 )
		{
			printf("#%d: YES\n", ++caseNum);
		}else{
			printf("#%d: NO\n", ++caseNum);
		}

	}
	return 0;
}
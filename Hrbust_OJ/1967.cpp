#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	while(getline(cin,s))
	{
		int sum=0;
		if (s[0] == '\0')
		{
			continue;
		}
		for (int i = s.length()-1; i >=0 ; --i)
		{
			if (48 <= s[i] && s[i] <= 57)
			{
				sum = sum + s[i]-48;
			}else{
				sum = sum + s[i] - 55;
			}
			
			// if(i == s.length() - 11) break;
		}
		if (sum % 11 == 0)
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}
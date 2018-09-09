#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	string s;
	while(getline(cin, s))
	{
		if (s[0] == 'Y')
		{
			printf("NO\n");
		}else if(s[0] == 'N'){
			printf("YES\n");
		}
	}
	return 0;
}
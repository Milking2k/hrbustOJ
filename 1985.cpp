#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	string s;
	while(getline(cin, s))
	{
		int sum=0;
		int dog=1;
		for (int i = s.length()-1; i >= 0; --i)
		{
			switch(s[i])
			{
				case 'A': sum+=10*dog;break;
				case 'B': sum+=11*dog;break;
				case 'C': sum+=12*dog;break;
				default : sum+=((int)s[i]-48)*dog;break;
			}
			dog*=13;
		}
		if (sum%13 == 0)
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}

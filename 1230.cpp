#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	string s;
	while(getline(cin, s))
	{
		for (unsigned int i = 0; i < s.length(); ++i)
		{
			switch(s[i])
			{
				case 'b':printf(" ");break;
				case 'q':printf(",");break;
				case 't':printf("!");break;
				case 'm':printf("l");break;
				case 'i':printf("e");break;
				case 'c':printf("a");break;
				case 'a':printf("c");break;
				case 'e':printf("i");break;
				case 'l':printf("m");break;
				default:printf("%c", s[i]);
			}
		}
			printf("\n");
	}
	return 0;
}
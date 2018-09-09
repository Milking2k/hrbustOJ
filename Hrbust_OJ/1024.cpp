#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int times;
	scanf("%d", &times);
	getchar();
	while(times--)
	{
		string s;
		getline(cin ,s);
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'z')
			{
				printf("%c", 'a');
			}else if (s[i] == 'Z')
			{
				printf("%c", 'A');
			}else{
				printf("%c", s[i]+1);
			}
		}
		printf("\n");
	}
	return 0;
}
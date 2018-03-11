#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	while(n--)
	{
		string s;
		getline(cin, s);
		for (int i = 0; i < s.length(); ++i)
		{
			if (0 != i)
				printf("-");
			switch(s[i])
			{
				case '0':printf("zero");break;
				case '1':printf("one");break;
				case '2':printf("two");break;
				case '3':printf("three");break;
				case '4':printf("four");break;
				case '5':printf("five");break;
				case '6':printf("six");break;
				case '7':printf("seven");break;
				case '8':printf("eight");break;
				case '9':printf("nine");break;
			}
		}
		printf("\n");
	}
	return 0;
}
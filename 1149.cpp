#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		string s;
		getline(cin, s);
		for (int i = s.length(); i >= 0; --i)
		{
			switch(s[i])
			{
				case '0':
				case '1':printf("O");break;
				case '2':
				case '3':printf("T");break;
				case '4':
				case '5':printf("F");break;
				case '6':
				case '7':printf("S");break;
				case '8':printf("E");break;
				case '9':printf("N");break;
			}
		}
		printf("\n");
	}
	return 0;
}
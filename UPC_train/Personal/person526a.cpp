#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

typedef long long LL;

int n;
int main()
{
	string s;
	getline(cin,s);
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]=='\0') break;
		if(i==0)printf("A");
		if(s[i]==' ') printf("%c", toupper(s[i+1]));
	}
	printf("\n");
	return 0;
}
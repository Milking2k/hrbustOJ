#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int count=1;
	int ans=0;
	for (int i = 0; i < s.length()-2; ++i)
	{
		if (s[i]!='-')
		{
			ans += (s[i]-'0')*count;
			count++;
		}
	}
	ans%=11;
	if(ans==(s[s.length()-1]-'0') || (ans == 10 && s[s.length()-1]=='X'))
		printf("Right\n");
	else
	{
		for (int i = 0; i < s.length()-1; ++i)
		{
			printf("%c", s[i]);
		}
		if(ans==10)
			printf("X\n");
		else if(ans<10)
			printf("%d\n", ans);
	}
	return 0;
}
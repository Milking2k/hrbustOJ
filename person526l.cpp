#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

typedef long long LL;
int n;
int m;
int ans[100007];
int main()
{
	// string s;
	char s[100007];
	while(~scanf("%s",s+1))
	{
		// int len = s.length();
		int len=strlen(s+1);
		int pos=5;
		ans[0]=1; 
		ans[1]=1;
		ans[2]=1;
		ans[3]=1;
		ans[4]=1;
		while(pos<=len)
		{
			if(s[pos-4]=='e'&&s[pos-3]=='r'&&s[pos-2]=='a'&&s[pos-1]=='s'&&s[pos]=='e'&&ans[pos-5])ans[pos]=1;
			else if(s[pos-4]=='d'&&s[pos-3]=='r'&&s[pos-2]=='e'&&s[pos-1]=='a'&&s[pos]=='m'&&ans[pos-5])ans[pos]=1;
			else if(s[pos-5]=='e'&&s[pos-4]=='r'&&s[pos-3]=='a'&&s[pos-2]=='s'&&s[pos-1]=='e'&&s[pos]=='r'&&ans[pos-6])ans[pos]=1;
			else if(s[pos-6]=='d'&&s[pos-5]=='r'&&s[pos-4]=='e'&&s[pos-3]=='a'&&s[pos-2]=='m'&&s[pos-1]=='e'&&s[pos]=='r'&&ans[pos-7])ans[pos]=1;
			pos++;
		}
		if(ans[len]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
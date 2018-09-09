// #include <iostream>
// #include <cstdio>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	char yuan;
	char mi;
	bool hasAns;
};
bool hasVis[30];
int sum=0;
node ans[30];

// bool cmp(node a,node b) {
// 	if(a.s==b.s) return a.k<b.k;
// 	return a.s>b.s;
// }

int main(int argc, char const *argv[])
{
	for (int i = 0; i < 26; ++i)
	{
		ans[i].yuan = (char)(i+'A');
		ans[i].hasAns = false;
		hasVis[i] = false;
		// cout << ans[i].yuan << endl;
	}
	string s1,s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); ++i)
	{
		int cur = (int)(s1[i]-'A');
		int cur2 =(int)(s2[i]-'A');
		// printf("%d  %d  %c  %c\n", cur,ans[cur].hasAns , ans[cur].mi, s2[i]);
		if (ans[cur].hasAns && ans[cur].mi == s2[i])
		{
			continue;
		}
		else if (ans[cur].hasAns && ans[cur].mi != s2[i])
		{
			printf("Failed\n");
			cin >> s1;
			return 0;
		}
		else if (!ans[cur].hasAns && !hasVis[cur2])
		{
			ans[cur].mi = s2[i];
			ans[cur].hasAns = true;
			hasVis[cur2] = true;
			sum++;
		}
		if(sum==26) break;
	}
	// printf("%d\n", sum);
	if(sum!=26) {
		printf("Failed\n");
		cin >> s1;
		return 0;
	}
	cin >> s1;
	for (int i = 0; i < s1.length(); ++i)
	{
		int cur = (int)(s1[i]-'A');
		printf("%c", ans[cur].mi);
	}
	printf("\n");

	return 0;
}
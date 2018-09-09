#include <bits/stdc++.h>
using namespace std;
int book[26];

bool isPrime(int a)
{
	if(a==0 || a==1) return 0;
	for (int i = 2; i < sqrt(a); ++i)
	{
		if(a%i==0) return 0;
	}
	return 1;
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	memset(book,0,sizeof(book));
	for (int i = 0; i < s.length(); ++i)
	{
		book[s[i]-'a']++;
	}
	int maxn = 0;
	int minn = 0x3f3f3f3f;
	for (int i = 0; i < 26; ++i)
	{
		if(book[i] > maxn) maxn = book[i];
		if(book[i] < minn && book[i] != 0) minn = book[i];
	}
	if(isPrime(maxn-minn))
		printf("Lucky Word\n%d\n",maxn-minn);
	else
		printf("No Answer\n0\n");
	
	return 0;
}
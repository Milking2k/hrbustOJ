#include <iostream>
#include <cstdio>
using namespace std;
unsigned int JSHash(string str)
{
	unsigned int hash = 1315423911;
	// char ch = ;
	int i=0;
	while(i < str.length())
	{
		hash ^= ((hash << 5) + (str[i]) + (hash >> 2));
		i++;
	}
	return hash & 0x7FFFFFFF;
}
int main(int argc, char const *argv[])
{
	string s1,s2,s3;
	// cin >> s1;
	cin >> s1 >> s2;
	cin >> s2 >> s3;
	cin >> s3 >> s1;
	int n;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		if (JSHash(s) == JSHash(s1))
		{
			cout << s3 << endl;
		}else if (JSHash(s) == JSHash(s2))
		{
			cout << s1 << endl;
		}else if (JSHash(s) == JSHash(s3))
		{
			cout << s2 << endl;
		}else{
			printf("Fake\n");
		}
	}
	return 0;
}
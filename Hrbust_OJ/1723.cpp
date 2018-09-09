//WA

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int times;
	scanf("%d",&times);
	while(times--)
	{
		
		string s1;
		string s2;
		string s3;
		cin >> s1 >> s2;
		int carry = 0;
		int len = max(s1.length(), s2.length());
		int i = s1.length()-1;
		int j = s2.length()-1;
		while(len >= 0)
		{
			int moreLen = max(i,j);
			carry = (s1[i] + s2[j] + carry)/16;
			s[moreLen] = (s1[i] + s2[j] + carry)%16;

		}

	}
	return 0;
}
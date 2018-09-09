#include <bits/stdc++.h>
using namespace std;

int lps(string s, int i, int j)
{
	if (i==j)
	{
		return 1;
	}
	if (i > j)
	{
		return 0;
	}
	if (tolower(s[i]) == tolower(s[j]))
	{
		return lps(s, i+1, j-1)+2;
	}
	return max(lps(s,i,j-1), lps(s, i+1, j));
}

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	cout << s.length() - lps(s,0,s.length()-1) << endl;
	return 0;
}
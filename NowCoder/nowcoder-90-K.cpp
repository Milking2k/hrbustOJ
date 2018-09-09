#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[200005];
	int b[200005];
	string s;
	cin >> s;
	int k;
	for (int i = 0; i < n; i = i+2*n)
	{
		for (k = 0; k < n; ++k)
		{
			a[k+i] = s[i+k];
		}
		a[k+i] = '0';
		for (k = n-2-1 ; k >= 0 && (k+i+n) < s.length(); --k)
		{
			a[k+i+n] = s[i+k+n];
		}
		a[k+i+n] = '0';
	}
	int count = n/s.length();
	if (n%s.length() != 0)
	{
		count++;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < s.length(); j = j+2*n)
		{
			if(a[j] != '0')
				printf("%c", a[j]);
		}
	}

	return 0;
}
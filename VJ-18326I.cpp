#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	// char s[10005];
	string s;
	while(cin >> s && s[0] != '0' && s.length() != 1)
	{
		// ;
		// if() break;
		int cnt=0;
		for (int i = s.length()-1; i >=0; --i)
		{
			cnt = (int)(s[i]-'0') - cnt;
			// printf("s[%d]:%c cnt:%d\n", i,s[i],cnt);
		}
		cnt = abs(cnt);
		if(cnt % 11 == 0) cout << s << " is a multiple of 11." << endl;
		else cout << s << " is not a multiple of 11." << endl;
	}
	
	return 0;
}
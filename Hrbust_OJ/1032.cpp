#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n)
	{
		if (0 == n)
		{
			cout << 1 << endl;
			continue;
		}
		int ans=1;
		for (int i = 1; i <= n; ++i)
		{
			ans = i*ans;
		}
		cout << ans << endl;
	}
	return 0;
}
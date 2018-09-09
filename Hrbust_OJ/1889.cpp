#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--)
	{
		int a, b;
		int sum=0;
		cin >> a;
		for (int i = 0; i < a; ++i)
		{
			cin >> b;
			sum += b;
		}
		cout << sum << endl;
	}
	return 0;
}
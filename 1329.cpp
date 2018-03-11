#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int a;
	while(cin >> a && a)
	{
		int sum=0,b;
		for (int i = 0; i < a; ++i)
		{
			cin >> b;
			sum += b;
		}
		cout << sum << endl;
	}
	return 0;
}
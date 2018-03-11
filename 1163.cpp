#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int a;
	while(cin >> a)
	{
		if (0 == a)
		{
			cout << 1 << endl;
		}
		else if(1 == a)
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
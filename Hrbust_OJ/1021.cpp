#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--)
	{
		int a,b;
		cin >> a >> b;
		if (a>=b)
		{
			cout << "MMM BRAINS" << endl;
		}else{
			cout << "NO BRAINS" << endl;
		}
	}
	return 0;
}
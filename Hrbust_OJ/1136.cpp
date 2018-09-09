#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	float a,b;
	while(cin >> a >> b)
	{
		// cout << a/b << endl;
		printf("%.2f\n", a/b);
	}
	return 0;
}
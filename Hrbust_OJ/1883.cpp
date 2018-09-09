#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b;
	while(cin >> a >> b && (a || b) )
		cout << a + b << endl;
	return 0;
}
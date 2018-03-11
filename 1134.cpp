#include <iostream>
#include <cstdio>
#include <cmath>
#define PI acos(-1)
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	while(cin >> n && n)
	{
		printf("%.2f\n", (n*n)/(2.0*PI));
	}
	return 0;
}
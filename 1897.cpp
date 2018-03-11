#include <iostream>
#include <cstdio>
#include <cmath>
#define PI acos(-1)
using namespace std;
int main(int argc, char const *argv[])
{
	float a,b;
	while( cin >> a >> b)
	{
		printf("%.2f\n", a*(PI*b*b)/3);
	}
	return 0;
}
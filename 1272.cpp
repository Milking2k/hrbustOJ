#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	float f;
	while(~scanf("%f",&f))
	{
		int x = f*100;
		double y = x/100.0;
		printf("%.2f\n", y);

	}
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	float a,b;
	while(cin >> a >> b)	
	{
		printf("%.2f\n", 0.99*a+0.01*b); 
	}
	return 0;
}
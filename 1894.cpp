#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	float x1,t1,x2,t2,w;
	while(~scanf("%f%f%f%f%f",&x1,&t1,&x2,&t2,&w))
	{	
		float V1 = (x1/t1+x2/t2)/2;
		float V2 = (x1/t1-x2/t2)/2;

		printf("%.2f\n",(w)/sqrt(V1*V1-V2*V2));
	}
	return 0;
}
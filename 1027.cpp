#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	int num;
	while(~scanf("%d", &num))
	{
		if(num%2 == 0)
			printf("%d\n", ((((num/2)%2011)*(((num+1))%2011))%2011));
		else{	
			printf("%d\n", ((((num)%2011)*(((num+1)/2)%2011))%2011));
		}
	}
	return 0;
}
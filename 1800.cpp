#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int x,y,i,j;
	while(cin>>x>>y>>i>>j)
	{
		if ((i-x)<=0 || (y+j)%(i-x) != 0)
		{
			printf("Back to the adult, it surely has something\n");
		}
		else{
			printf("He is right\n");
		}
	}
	return 0;
}
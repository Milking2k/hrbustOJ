#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	int times;
	cin >> times;
	while(times--){
		int u,v,w,l;
		cin >> u >> v >> w >> l;
		printf("%.3f\n", (1.0*l)*((1.0*w)/(1.0*(u+v))));
	}

	return 0;
}
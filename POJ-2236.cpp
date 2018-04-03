#include <iostream>
#include <cstdio>
using namespace std;

struct point
{
	int x,y;
};

ans[1005];
point pot[10005];


int foo(int x)
{
	return ans[x]==x? x : ans[x]=foo(ans[x]);
}

int main(int argc, char const *argv[])
{
	int n,d;
	cin >> n >> d;
	
	return 0;
}
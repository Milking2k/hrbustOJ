#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int l,r,a;
	cin >> l >> r >> a;
	int cha = abs(l-r);

	if(cha >= a)
	{
		printf("%d\n", 2*(min(l,r)+a));
	}else{
		a = (a - cha)/2;
		printf("%d\n", 2*(max(l,r)+a));
	}
	return 0;
}
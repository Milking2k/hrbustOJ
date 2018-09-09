#include <iostream>
#include <cstdio>
#include <iomanip>
#include <cmath>
using namespace std;
// fixed << setprecision(2)
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int a,b,r;
		cin >> a >> b >> r;
		double cnt = exp(a);
		cout << fixed << setprecision(r) << cnt*b << endl;

	}
	
	return 0;
}
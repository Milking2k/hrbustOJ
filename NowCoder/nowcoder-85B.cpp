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
		double cnt = pow(a,exp(1));
		cout << fixed << setprecision(r) << cnt/(b*1.0) << endl;

	}
	
	return 0;
}
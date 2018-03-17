#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int a,b,c,d,t;
	while(cin >> a >> b >> c >> d >> t)
	{
		
		// cout << a << " " << b << " " << endl;
		long long int ans = 1;
		long long int cnt = 1;
		for (int i = 0; i < c; ++i)
		{
			cnt = ((cnt%t) * ((a%t)*(b%t))%t)%t;
			// cout << cnt << endl;
		}
		for (int i = 0; i < d; ++i)
		{
			ans = ((ans%t)*(cnt%t))%t;
			// cout << ans << endl;
		}
		cout << ans%t << endl;
	}
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
int main(int argc, char const *argv[])
{
	long long ans;
	int a,b,c,d,e;
	while(cin >>a>>b>>c>>d>>e)
	{
		ans = (( ((a%e)*(b%e))%e ) * ( (c%e)*(d%e)%e ))%e;
		cout << ans << endl;
	}
	return 0;
}
// 1000000000
//  999999999
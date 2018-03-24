#include <bits/stdc++.h>
using namespace std;
#define ine 0.00000001
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int a,b;
		double x,y;
		cin >> x >> a >> y >> b;
		double ans1 = a*log(x);
		double ans2 = b*log(y);
		if (ans1 - ans2 <= ine)
		{
			printf("Yes\n");
			continue;
		}else{
			printf("No\n");
		}	
	}
	return 0;
}
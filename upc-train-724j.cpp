#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t,n,m,k,b,res;

long long Mode(long long a, long long b, long long mode)
{
	long long sum = 1;
	a = a % mode;
	while (b > 0) {
		if (b % 2 == 1)
			sum = (sum * a) % mode;
		b /= 2;
		a = (a * a) % mode;
	}
	return sum;
}
int main()
{
    res=1;
    scanf("%lld%lld%lld",&b,&n,&k);
    res = Mode(b,n,k);
    printf("%lld\n",res%k);
    return 0;
}

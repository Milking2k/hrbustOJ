// timeout

#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;
int ans[100000];
long long int next;
long long int foundNum(long long int a)
{
	int carry=0;
	long long int ans=0;
	long long int multiple = 1;
	while(a || carry == 1)
	{
		int cnt = a%10 + carry;
		if (cnt <= 4)
		{
			ans += 4*multiple; 
			multiple *= 10;
		}else if (cnt > 7)
		{
			ans += 4*multiple;
			carry = 1;
			multiple *= 10;
		}else
		{
			ans += 7*multiple;
			multiple *= 10;
		}
		a/=10;
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	long long int l,r;
	while(cin >> l >> r)
	{
		long long int sum=0;
		long long int cnt = 0;
		for (long long int i = l; i <= r; ++i)
		{
			cnt = foundNum(i);
			if (cnt < r)
			{
				sum += cnt*(cnt-i+1);
				i = cnt;
			}else{
				sum += cnt*(r-i+1);
				break;
			}
		}
		printf("%lld\n", sum);
	}
	
	return 0;
}
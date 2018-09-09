// #include <iostream>
// #include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int a0,a1,b0,b1;
		cin >> a0>>a1>>b0>>b1;
		int k1 = a0/a1;
		int k2 = b1/b0;
		int ans=0;
		for (int x = 1; x*x <= b1; ++x)
		{
			if (b1%x==0)
			{
				if (x%a1==0&&gcd(x/a1,k1)==1 && gcd(k2,b1/x)==1)
				{
					ans++;
				}
				int k3=b1/x;
				if(x==k3)continue;
				if (k3%a1==0&&gcd(k3/a1,k1)==1&&gcd(k2,b1/k3)==1) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
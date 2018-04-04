#include <bits/stdc++.h>
// #include <iostream>
// #include <cstdio>
// #include <algorithm>
typedef long long int ll;
using namespace std;
// int gcd(int a,int b){return a%b==0? b : gcd(b,a%b);}
int main(int argc, char const *argv[])
{
	ll n,x;
	cin >> n >> x;
	ll ans=0;
	ans = 3*(n-__gcd(n,x));
	printf("%lld\n", ans);
	return 0;
}
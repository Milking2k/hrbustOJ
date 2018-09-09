// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define rd(x) scanf("%d",&x)
int n;
int a[1000005];

int main()
{
	// freopen("in.txt","r",stdin);

	while(~rd(n))
	{
		for (int i = 1; i <= n; ++i) rd(a[i]);
		sort(a+1,a+n+1);
		printf("%d\n", a[(n+1)/2]);
	}
	return 0;
}
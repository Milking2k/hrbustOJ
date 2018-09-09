// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int flag;
int x;
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	flag=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&x);
		if(x%2==1) flag = 1;
	}
	if(flag)printf("First\n");
	else printf("Second\n");

	return 0;
}
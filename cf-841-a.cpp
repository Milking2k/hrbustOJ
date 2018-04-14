// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[30]={0};
int pos[30]={0};
int n,k;
char ch;

int main(int argc, char const *argv[])
{
	while(cin>>n>>k)
	{
		for(int i=0;i<n;i++)
		{
			cin >> ch;
			a[(int)(ch-'a')]++;
			// printf("%d\n", a[(int)(ch-'a')]);
		}
		sort(a,a+27);
		// printf("\n");
		if(a[26]>k) printf("NO\n");
		else printf("YES\n");

	}
	return 0;
}
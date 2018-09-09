// #include <iostream>
// #include <cstdio>
#include <bits/stdc++.h>
using namespace std;

struct node
{
	int k,s;
};

bool cmp(node a,node b) {
	if(a.s==b.s) return a.k<b.k;
	return a.s>b.s;
}

int main(int argc, char const *argv[])
{
	// int a = 3;
	// printf("%.f\n", a*1.6);
	// printf("floor:%.f\n",ceil(a*1.6));

	int n,m;
	cin >> n >> m;
	struct node a[5005];
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].k >> a[i].s;
		// printf("%d %d\n", a[i].k,a[i].s);
	}
	sort(a,a+n,cmp);
	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%d %d\n", a[i].k,a[i].s);
		
	// }
	int cnt = m*1.5;
	// printf("%d\n", cnt);
	int sum=0;
	for (int i = 0; a[i].s >= a[cnt-1].s; ++i)
	{
		// printf("a.s:%d  a[cnt].s%d\n", a[i].s,a[cnt].s);
		sum++;
	}
	printf("%d %d\n", a[cnt-1].s,sum);
	for (int i = 0; i < sum; ++i)
	{
		cout << a[i].k << " " << a[i].s << endl;
	}


	return 0;
}
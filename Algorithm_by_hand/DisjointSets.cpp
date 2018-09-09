#include <bits/stdc++.h>
using namespace std;
#define maxn 10000
int e[maxn];// relationShip

int disjointSets(int n)
{
	if(e[n] != n) n=disjointSets(e[n]);
	return n;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		// cin >> e[i];
		e[i] = i;
	}
	int a,b;
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		a = disjointSets(a);
		b = disjointSets(b);
		e[a] = b; // a 归属到b中
	}
	while(cin >> a >> b)
	{
		a = disjointSets(a);
		b = disjointSets(b);
		printf("%d %d\n", a,b);
		if (a==b)
		{
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}	
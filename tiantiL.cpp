#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct people
{
	int index;
	int h;
};
int cmp(people a, people b)
{
	return a.h < b.h;
}
int main(int argc, char const *argv[])
{
	struct people a[100005];
	int n;
	while(cin >> n)
	{
		for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].h;
			a[i].index = i;
		}
		sort(a+1,a+n+1,cmp);
		// for (int i = 1; i <= n; ++i)
		// {
		// 	printf("a[%d].%d=%d  ", i,a[i].index,a[i].h);
		// }
		if (n!=1 && a[n].h == a[n-1].h)
		{
			printf("-1\n");
		}
		else{
			printf("%d\n", a[n].index);
		}
	}
	return 0;
}

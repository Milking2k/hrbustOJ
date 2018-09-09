#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int a[1003];
int sum;
int n,t;
int m = 1025;
int pos=0;
int check(int cnt,int minx)
{
	if (pos+1 == n)
	{
		return sum;
	}
	int m=1025;
	int x = cnt;
	while(abs(x - t) < m && abs(x - t) < minx)
	{
		minx = abs(x - t);
		scanf("%d",&cnt);
		if(abs(x + cnt - t) < m){
			pos++;
			check(x+cnt,m);
			sum += (x+cnt-t)*(x+cnt-t);
			return sum;
		}
		else{
			sum += (x-t)*(x-t);
			pos++;
			return check(x,minx);
		}
	}
	return sum;
}

int main()
{
	while(~scanf("%d%d", &n,&t))
	{
		sum=0;
		int aaa;
		memset(a,0,sizeof(a));

		scanf("%d",&aaa);
		check(aaa,1025);
		printf("%d\n", sum);
		
	}
	return 0;
}
	// for (int i = 0; i < n; ++i)
		// {
		// 	scanf("%d",&a[i]);
		// }
		// a[n] = 12;
		// for (int i = 0; i < n; ++i)
		// {
		// 	m=12;
		// 	int x = a[i];
		// 	while(abs(x - t) < m)
		// 	{
		// 		m = abs(x - t);
		// 		i++;
		// 		x += a[i];
		// 	}
		// 	x -= a[i];
		// 	i--;
		// 	sum += (x-t)*(x-t);
	// }
/*
地毯覆盖/多次覆盖最后查询某点显示的是哪层地毯
*/


#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

#define ll long long int
#define INF 0x3f3f3f3f



int n;
int a[1000005][4];

int main(int argc, char const *argv[])
{
	// freopen("in.txt","r",stdin);

	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
		a[i][2] += a[i][0];
		a[i][3] += a[i][1];
	}
	int x,y;
	scanf("%d%d",&x,&y);
	int ans=-1;
	for (int i = 1; i <= n; ++i)
	{
		if(a[i][0] <= x && x <= a[i][2] && 
		   a[i][1] <= y && y <= a[i][3]
			)
			ans = i;
	}
	printf("%d\n", ans);

	return 0;
}


/*

#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctype>

using namespace std;

#define ll long long int
#define INF 0x3f3f3f3f





int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);



	return 0;
}

*/
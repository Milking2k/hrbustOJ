#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int a[3][2];
	for (int i = 0; i < 3; ++i)
	{
		cin >> a[i][0] >> a[i][1];
	}
	int minx=0x3f3f3f3f;
	for (int i = 0; i < 3; ++i)
	{
		int cnt;
		// if (n >= a[i][0])
		// {
		// 	cnt = n/a[i][0];
		// 	if(n % a[i][0] != 0) cnt++;			
		// }else{
		// 	cnt++;
		// }

		// if (cnt * a[i][1] < minx)
		// {
		// 	minx = cnt*a[i][1];
		// }

		if (n%a[i][0] == 0)
		{
			cnt = n/a[i][0];
		}else{
			cnt = n/a[i][0] + 1;
		}
		if (cnt*a[i][1] < minx)
		{
			minx = cnt*a[i][1];
		}
	}
	printf("%d\n", minx);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool tofactor(int x)
{
	int n = x;
	int cnt=0;
	// int end = sqrt(n*1.0);
	for (int i = 2; i <= n/2; ++i)
	{
		if (n%i == 0)
		{
			// printf("%d ", i);
			cnt += i;
			// printf("i:%d cnt:%d\n", i,cnt);
		}
	}
	if (cnt+1 == x)
	{
// printf(" x:   %d\n", x);
		return true;
	}else{
		return false;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin>> n;
	while(n--)
	{
		int a,b,ans=0;
		cin >> a>> b;
		if (a>b)
		{
			swap(a,b);
		}
		for (int i = a; i <= b; ++i)
		{
			if (tofactor(i))
			{
				ans++;
			}
			
		}
			printf("%d\n", ans);
	}
	return 0;
}
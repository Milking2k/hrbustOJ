#include <bits/stdc++.h>
using namespace std;
int ans=3;
// int time=0;
int foo(int time,int ans)
{
	if (time == 0)
	{
		return ans ;
	}
	ans = (ans-1)*2;
	time--;
	return foo(time,ans);
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while(n--)
	{
		int time;
		cin >> time;
		printf("%d\n", foo(time,3));
	}
	return 0;
}
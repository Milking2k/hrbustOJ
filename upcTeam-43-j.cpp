#include <bits/stdc++.h>
using namespace std;


int n,ans,a[100100];

int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a+1,a+1+n);
	reverse(a+1,a+1+n);
	for (int i = 1; i <= n; ++i)
	{
		if(i+1 > a[i+1])
		{
			for (int j = i+1; a[j] == i; ++j)
			{
				ans ^= 1;
			}
			ans |= (a[i]-i) & 1;
			puts(ans?"First":"Second");
			return 0;
		}
	}

	return 0;
} 
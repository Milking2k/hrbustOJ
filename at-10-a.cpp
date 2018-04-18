#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int a;
	int ans=0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a);
		if(a%2) ans++;
	}
	if(ans%2) printf("NO\n");
	else printf("YES\n");
	return 0;
}
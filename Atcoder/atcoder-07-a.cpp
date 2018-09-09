#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m;
	char c;
	int ans=0;
	cin >> n >> m;
	for (int i = 0; i < n*m; ++i)
	{
		cin >> c;
		if(c=='#') ans++;
	}
	if(ans==n+m-1) printf("Possible\n");
	else printf("Impossible\n");
	return 0;
}
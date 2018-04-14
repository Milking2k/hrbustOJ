#include <bits/stdc++.h>
using namespace std;
int main()
{
	int J, L, i, o;
	while(~scanf("%d%d%*d%d%d%*d%*d", &i, &o, &J, &L))
	{
		int cnt = J % 2 + L % 2 + i % 2;
		if(J > 0 && L > 0 && i > 0 && 3 - cnt < cnt)
			cnt = 3 - cnt;
		printf("%lld\n", 0LL + J + L + i + o - cnt);
	}
	return 0;
}
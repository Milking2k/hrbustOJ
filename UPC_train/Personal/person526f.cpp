#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f3f3f3f

typedef long long LL;
int n;
int main()
{
	LL a,b,c;
	while(~scanf("%lld%lld%lld",&a,&b,&c))
	{
		LL cnt1=b/c;
		LL cnt2=a/c;
		if(a%c==0) printf("%lld\n", cnt1-cnt2+1);
		else printf("%lld\n", cnt1-cnt2);
	}	
	return 0;
}
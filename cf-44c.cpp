#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// --------------------
ll emt[100007];
int main()
{
	ll n,k,l,i,j;
	scanf("%lld %lld %lld",&n,&k,&l);
	for (i = 1; i <= n*k; ++i) scanf("%lld",&emt[i]);
	sort(emt+1,emt+1+n*k);

	int c=0;
	for (i = 1; i <= n*k; ++i)
		if(emt[i]-emt[1]<=l)
			c++;
	if(c<n) return !printf("0\n");

	std::vector<int> vl;
	vl.push_back(1);
	for(i = n-1;i>=1;i--)
	{	
		ll t = vl.back()+k;
		if(t>=c-i+1)
		{
			for(j=c-i+1;j<=c;j++) vl.push_back(j);
			break;
		}
		else vl.push_back(t);
	}
	ll ans=0;
	for(auto it:vl) ans += emt[it];
	return !printf("%lld\n", ans);
}
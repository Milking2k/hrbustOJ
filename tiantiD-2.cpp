#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rd(x) scanf("%d",&x)
#define rdd(x,y) scanf("%d%d",&x,&y)

struct node
{
	string s;
	int id;
	int scoreSelf;
	int scoreAll;
	char isleader;
	char iswest;
	int paperNum;
	ll money;
}emt[105];

int n,k;
int emtInrc[15];
// int emt[20005];

bool cmp(node a,node b)
{
	if(a.money==b.money) return a.id<b.id;
	else return a.money > b.money;
}

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	while(cin >> n)
	{
		ll allmoney=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> emt[i].s >> emt[i].scoreSelf >> emt[i].scoreAll
			    >> emt[i].isleader >> emt[i].iswest >> emt[i].paperNum;
			emt[i].id = i;
			ll cnt=0;
			if(emt[i].scoreSelf > 80)
			{
				if(emt[i].paperNum>0) cnt+=8000;
				if(emt[i].isleader=='Y') cnt+=850;
				if(emt[i].iswest=='Y' && emt[i].scoreSelf > 85) cnt+=1000;
				if(emt[i].scoreAll > 80 && emt[i].scoreSelf > 85) cnt+=4000;
				if(emt[i].scoreSelf > 90) cnt+=2000;
			}
			emt[i].money = cnt;
			// cout << cnt << endl;
			allmoney += cnt;
		}
		sort(emt,emt+n,cmp);
		// printf("%\n");
		cout << emt[0].s << endl;
		cout << emt[0].money << endl;
		cout << allmoney << endl;
	}
	return 0;
}
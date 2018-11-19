#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll inf=1e18+2137;
int n,m,k,a,b,w,odw[300001],kr[300001];
vector<int> wynik;
ll d[300001];
vector<pair<pii,int> > v[300001];
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll, int> > >pq;
int main() {
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1; i<=m; i++) {
		scanf("%d%d%d",&a,&b,&w);
		v[a].emplace_back(make_pair(b,w),i);
		v[b].emplace_back(make_pair(a,w),i);
	}
	for (int i=2; i<=n; i++) d[i]=inf;
	pq.emplace(0,1);
	while (!pq.empty()) {
		ll odl=pq.top().first;
		int x=pq.top().second;
        printf("x::%d\n", x);
		pq.pop();
		if (odw[x]) continue;
		odw[x]=1;
		if (x!=1) wynik.push_back(kr[x]);
		for (auto k:v[x]) {
			int nast=k.first.first;
			int waga=k.first.second;
			if (d[nast]>odl+waga) {
				d[nast]=odl+waga;
				pq.emplace(odl+waga,nast);
				kr[nast]=k.second;
			}
		}
	}
	int zost=min((int)wynik.size(),k);
	printf("%d\n",zost);
	for (int i=0; i<zost; i++) printf("%d ",wynik[i]);
	puts("");
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = a; i<n; i++)
#define per(i,a,n) for (int i = n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e5+7;
int dist[N][110];
int n, m, k, s;

vector < int > g[N];
vector < int > L[110];

void bfs(int t)
{
	for (int v = 1; v <= n; v++)dist[v][t] = N;
	queue < int > q;
	for (auto v: L[t]){
		dist[v][t] = 0;
		q.push(v);
	}
	
	while(q.empty() == false){
		int u = q.front();
		q.pop();
		for (auto to : g[u]){
			if(dist[u][t] + 1 < dist[to][t]){
				dist[to][t] = dist[u][t] + 1;
				q.push(to);
			}
		} 
	}
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &s);
	
	for (int v = 1; v <= n; v++){
		int a;
		cin >> a;
		L[a].push_back(v);
	}
	
	for (int i = 0; i < m; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		g[x].push_back(y);
	 	g[y].push_back(x);
	}
	for (int i = 1; i <= k; i++) bfs(i); 	
			
	for (int v = 1; v <= n; v++){
		sort(dist[v] + 1, dist[v] + k + 1);
		int cnt = 0;
		for (int i = 1; i <= s;i++){
			cnt += dist[v][i];
		}
		printf("%d ",cnt);
	}
	 
}
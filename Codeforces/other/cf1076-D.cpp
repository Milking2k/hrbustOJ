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
typedef pair<ll,ll> PII;
const ll mod = 1000000007;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 1e6+7;
const int M = 1e6 + 7;
const ll INF = 1e18 + 2137;

int T,n,m,k;

int tot = 0,head[N],ver[N],nxt[M],wei[M],nums[M];
void add(int num, int x, int y, int z)
{
    ver[++tot] = y;
    nums[tot] = num;
    wei[tot] = z;
    nxt[tot] = head[x];
    head[x] = tot;
}

ll dist[N];
bool vis[N];
int kr[N];
VI ans;
ll dijkstra(){
    priority_queue<PII> q;
    rep(i, 2, n+1) dist[i] = INF;
    dist[1] = 0;
    q.emplace(0, 1);
    while(q.size())
    {
        ll x = q.top().se;q.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        if(x!=1) ans.pb(kr[x]);
        for (int i = head[x]; i;i=nxt[i]){
            int y = ver[i], z = wei[i];
            if (dist[y] > dist[x] + z)
            {
                dist[y] = dist[x] + z;
                q.emplace(-dist[y], y);
                kr[y] = nums[i];
            }
        }
    }
    // while (!q.empty()) {
	// 	ll odl=q.top().first;
	// 	int x=q.top().second;
	// 	q.pop();
	// 	if (vis[x]) continue;
	// 	vis[x]=1;
	// 	if (x!=1) ans.push_back(kr[x]);
	// 	for (int i = head[x]; i;i=nxt[i]) {
	// 		int nast=ver[i];
	// 		int waga=wei[i];
	// 		if (dist[nast]>odl+waga) {
	// 			dist[nast]=odl+waga;
	// 			q.emplace(odl+waga,nast);
	// 			kr[nast]=nums[i];
	// 		}
	// 	}
	// }
}


int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    rep(i,1,m+1){
        int u, v, w;
        cin >> u >> v >> w;
        add(i, u, v, w);
        add(i, v, u, w);
    }
    dijkstra();

    int len = min((int)ans.size(), k);
    cout << len << endl;
    rep(i,0,len){
        cout << ans[i] << " ";
    }
    return 0;
}


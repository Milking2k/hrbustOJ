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
const int N = 1e3+7;
const int M = 1e6 + 7;
int T,n,m;
int a[N];
int s, t;

int head[N], edge[M], ver[M], Next[M], tot;
void addedge(int x, int y, int z)
{
    edge[++tot] = z, ver[tot] = y, Next[tot] = head[x], head[x] = tot;
}

int dist[N];
// int v[N];
priority_queue<PII, vector<PII>, greater<PII> > pq;
void dijkstra()
{
    //init
    while(pq.size()) pq.pop();
    rep(i, 0, n + 1) dist[i] = 0x3f3f3f3f;

    pq.push({dist[s] = 0, s});
    // v[s] = 1;

    while(!pq.empty()) {
        PII cur = pq.top();pq.pop();
        int x;
        if(dist[x = cur.se] < cur.fi) continue;
        for (int i = head[cur.se]; i; i = Next[i]) {
            // if(v[i]) continue;
            int relLen = dist[x] + edge[i];
            if(relLen < dist[ver[i]]){
                if(a[ver[i]] != 0 && (relLen / a[ver[i]]) & 1)
                    pq.push({dist[ver[i]] = (relLen / a[ver[i]] + 1) * a[ver[i]], ver[i]});
                else {
                    pq.push({dist[ver[i]] = relLen, ver[i]});
                }
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scanf("%d",&T);
    for (int _ = 0; _ < T; _++)
    {
        memset(head, 0, sizeof(head));
        tot = 0;

        scanf("%d%d", &n, &m);
        rep(i, 1, n + 1) scanf("%d", a + i);
        rep(i, 1, m+1) {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            addedge(u, v, w);
            addedge(v, u, w);
        }
        scanf("%d%d", &s, &t);
        dijkstra();
        rep(i,1,n+1)
            printf("%d ", dist[i]);
    }
    
    return 0;
}
/*
1
9 14
3
5
7
3
5
7
9
3
5
1 2 4
1 8 8
2 3 8
2 8 11
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 9 6
7 8 1
8 9 7
1 5
*/
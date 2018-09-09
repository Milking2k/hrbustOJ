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
const int M = 1e6+7;
int T,n,m;
int a[N];
int g2g[N][N];

int head[N], ver[M], Next[M], tot;
void add(int x, int y){
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

int deg[N],topo[N];
bool topsort()
{
    int u;
    int t = 0;
    priority_queue<int, vector<int>, greater<int> > q;
    rep(i,1,n+1){
        if(!deg[i]){
            q.push(i);
        }
    }
        // printf("begin: %d\n", q.top());
    while(q.size()){
        // puts("test");
        topo[t++] = q.top();
        u = q.top();
        q.pop();
        for (int i = head[u]; i;i = Next[i]){
            int v = ver[i];
            deg[v]--;
            if(!deg[v])
                q.push(v);
        }
    }
    return t == n;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin >> n >> m && n && m){
        memset(g2g, 0, sizeof(g2g));
        memset(deg, 0, sizeof(deg));
        memset(head, 0, sizeof(head));
        tot = 0;

        rep(i,1,m+1)rep(j,1,n+1){
            cin >> a[j];
            per(k,1,j){
                g2g[ a[k] ][ a[j] ]++;
            }
        }
        // puts("a");
        rep(i,1,n+1)rep(j,i+1,n+1){
            if (g2g[i][j] > g2g[j][i])
                add(i, j),deg[j]++;
            if(g2g[i][j] < g2g[j][i])
                add(j, i),deg[i]++;
        }

        if (!topsort()){
            cout << "No solution\n";
        }
        else{
            rep(i,0,n){
                cout << topo[i];
                i != n-1 ? cout << " " : cout << "\n";
            }
        }
    }
    return 0;
}
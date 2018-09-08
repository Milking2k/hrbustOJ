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
const int N = 1e5+7,M=10010,inf=1000000010;
int n,m,k,S,T,i,x,y,z,mxt;
int g[N], h[N], v[M << 1], w[M << 1], nxt[M << 1], ed, d[N], vis[N], ans[N];
priority_queue<PII, vector<PII>, greater<PII>> Q;
void add(int x, int y, int z){
    v[++ed] = x;    w[ed] = z;    nxt[ed] = g[y];    g[y] = ed;
    v[++ed] = y; w[ed] = z; nxt[ed] = g[x]; h[x] = ed;
}
int main()
{
    // ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin >> n >> m){
        // rep(i, 1, k + 3) ans[i] = -1;
        memset(ans, -1, sizeof(ans));
        memset(g, 0, sizeof(g));
        memset(h, 0, sizeof(h));
        memset(vis, 0, sizeof(vis));
        while(!Q.empty())
            Q.pop();

        cin >> S >> T >> k >> mxt;
        rep(i,1,m+1){
            cin >> x >> y >> z;
            add(x, y, z);
        }
        rep(i,1,n+1){
            d[i] = inf;
            Q.push(PII(d[T] = 0, T));
        }
        while(!Q.empty()){
            PII t = Q.top();
            Q.pop();
            if(d[t.se] < t.fi) 
                continue;
            for (int i = g[x = t.se]; i;i=nxt[i])if(d[x]+w[i]<d[v[i]]){
                    Q.push(PII(d[v[i]] = d[x] + w[i], v[i]));
            }
        }
        if(d[S] < inf)
            Q.push(PII(d[S], S));
        while(!Q.empty()){
            PII t = Q.top();
            Q.pop();
            vis[x = t.se]++;
            if(x==T && vis[T] <= k){
                ans[vis[T]] = t.fi;
                // if(t.fi > mxt){
                //     cout << t.fi << endl;
                //     break;
                // }
            }
            if(vis[T]>k)
                break;
            if(vis[x] <= k){
                for (i = h[x]; i; i = nxt[i]){
                    Q.push(PII(t.fi - d[x] + d[v[i]] + w[i], v[i]));
                }
            }
        }
        rep(i,1,k+1)
            cout << ans[i] << endl;
        if(ans[k] <= mxt && ans[k] != -1){
            cout << "yareyaredawa\n";
        }
        else{
            cout << "Whitesnake!\n";
        }

    }
    return 0;
}

/*
2 10
1 2 1000 1000
1 2 42
1 2 1
1 1 79
2 2 65
2 2 82
1 2 92
2 1 28
2 1 5
2 1 93
2 1 17

*/
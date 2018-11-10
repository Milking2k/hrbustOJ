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
int T,n,m;

/*2sat*/
const int MAXN = 20020;
const int MAXM = 100010;
struct Edge
{
    int to, next;
} edge[MAXM];
int head[MAXN], tot;
void init()
{
    tot = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
bool vis[MAXN];   //染色标记，为 true 表示选择
int S[MAXN], top; //栈
bool dfs(int u)
{
    if(vis[u^1])return false;
    if(vis[u])return true;
    vis[u] = true;
    S[top++] = u;
    for (int i = head[u]; i != -1; i = edge[i].next)
        if (!dfs(edge[i].to))
            return false;
    return true;
}
bool Twosat(int n)
{
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < n; i += 2)
    {
        if (vis[i] || vis[i ^ 1])
            continue;
        top = 0;
        if (!dfs(i))
        {
            while (top)
                vis[S[--top]] = false;
            if (!dfs(i ^ 1))
                return false;
        }
    }
    return true;
}

int a[MAXN], b[MAXN], c[MAXN],dep;
bool solve(int mid)
{
    init();
    rep(i,1,mid+1){
        if(c[i]==0){
            addedge(a[i] << 1, b[i] << 1 ^ 1);
            addedge(b[i] << 1, a[i] << 1 ^ 1);
        }
        else if(c[i]==1){
            addedge(a[i] << 1, b[i] << 1);
            addedge(b[i] << 1, a[i] << 1);
            addedge(a[i] << 1 ^ 1, b[i] << 1 ^ 1);
            addedge(b[i] << 1 ^ 1, a[i] << 1 ^ 1);
        }
        else{
            addedge(a[i] << 1 ^ 1, b[i] << 1);
            addedge(b[i] << 1 ^ 1, a[i] << 1);
        }
    }
    return Twosat(2*mid);
}

int main()
{
    for (scanf("%d", &T); T;T--){
        scanf("%d%d", &n, &m);
        rep(i,1,m+1){
            scanf("%d%d%d", &a[i], &b[i], &c[i]);
        }
        int l = 1, r = m;
        int ans = 1;
        while(l<=r){
            int mid = (l + r) / 2;
            // printf("mid:%d\n", mid);
            if(solve(mid)){
                l = mid+1;
                if(ans<mid) ans=mid; 
            }
            else{
                r = mid-1;
            }
        }
        printf("%d\n", ans);
    }
}
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
const int N = 7e2+7;
int T,n,m;
bool f[N][N], g[N][N];
int col[N], ans = 0x7fffffff, now, num[3];
inline int Get(int x){ return x*(x-1)>>1;}
bool dfs(int x, int c)
{
    col[x] = c, num[c]++;
    rep(i,1,n+1) if(!g[x][i]) {
        if(!col[i] && !dfs(i,3-c))
            return 0;
        else if(col[i]==c)
            return 0;
    }
    return 1;
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i,1,m+1){
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = 1, g[v][u] = 1;
    }
    f[0][0] = 1;
    rep(i, 1, n + 1) g[i][i] = 1;
    rep(i,1,n+1) if(!col[i]) {
        num[1] = num[2] = 0;
        if(!dfs(i,1)){
            puts("-1");
            return 0;
        }

        now++;
        rep(j, 0, n + 1) if (f[now - 1][j]) 
            f[now][j + num[1]] = f[now][j + num[2]] = 1;
    }
    rep(i, 0, n + 1) if (f[now][i]) 
        // ans = min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2);
        ans=min(ans,Get(i)+Get(n-i));
    printf("%d\n", ans);
    return 0;
}
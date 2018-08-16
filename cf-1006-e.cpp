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

const int N = 2e5+7;
int T,n,m,k,q,tot;
int head[N],ver[N],Next[N];
int v[N];
struct node
{
    int l,r;
}range[N];
vector <int> a[N];
int ans[N];
void dfs(int x){
    ans[++m] = x;
    range[x].l = m;
    v[x] = 1;
    for(auto i:a[x]){
        int y = i;
        if(v[y])continue;
        dfs(y);
    }
    range[x].r = m;
}

int main()
{
    tot=0,m = 0;
    read(n), read(q);

    rep(i,2,n+1){
        int x;
        read(x);
        a[x].pb(i);
    }

    rep(i,1,n+1) sort(a[i].begin(), a[i].end());
    dfs(1);

    rep(i,1,q+1) {
        int u,k;
        read(u),read(k);
        if(k>range[u].r-range[u].l+1) printf("-1\n");
        else printf("%d\n",ans[range[u].l + k-1]);
    }
    return 0;
}

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
int T,n,m,k;
int a[N];
ll v[N];
int fa[N];
int get(int x){
    if(x== fa[x]) return x;
    return fa[x] =get(fa[x]);
}
void unite(int x,int y){
    fa[get(x)] = get(y);
}
vector<int> it[N];
int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%d%d",&n,&m);
        rep(i,0,n) scanf("%d",&v[i]),it[i].clear();
        rep(i,0,n) fa[i] = i;
        rep(i,1,m+1){
            int u,v;
            scanf("%d%d",&u,&v);
            u--,v--;
            unite(u ,v);
        }
        ll ans=0;
        rep(i,0,n) it[get(i)].pb(v[i]);
        rep(i,0,n){
            if(it[i].empty()) continue;
            sort(all(it[i]));
        }
        int dp[32];
        rep(i,0,n){
            memset(dp, 0, sizeof(dp));
            for(auto &t: it[i]){
                rep(j,0,30){
                    if(t & (1<<j)){
                        ans = (ans + (1ll*t*dp[j]%mod)*(1<<j))%mod;
                        dp[j]++;
                    }
                }
            }
        }
        printf("%I64d\n",ans);
    }

    return 0;
}

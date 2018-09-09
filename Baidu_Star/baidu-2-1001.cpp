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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head


const int N = 1e6+7;

int T,n,m,k;
int a[N],head[2*N];
PII pi[N];
int fa[N];
int vis[N];
int get(int x){
    if(x==fa[x]) return x;
    return fa[x] = get(fa[x]);
}
void mrge(int x, int y){
    fa[get(x)] = get(y);
}

void solve()
{
    int ans = 0;
    rep(i,0,n){
        int cnt = max(0, m-vis[i]-k);
        ans = max(ans, n-cnt-1);
    }
    printf("%d\n",ans);
}


int main()
{
    for(scanf("%d",&T);T;T--){
        scanf("%d%d%d",&n,&m,&k);
        rep(i,0,n+1) vis[i]=0;
        rep(i,1,m+1){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x > y ) swap(x,y);
            vis[x]++;
            vis[y]++;
//            pi[i] = mp(x,y);
        }
//        rep(i,0,n){
//            printf("sss::%d %d\n",i,vis[i]);
//        }
        solve();
    }
    return 0;
}

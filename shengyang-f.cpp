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
int T,n,m,l,r,k,Cas=1;
// int a[N];

int ver[N], head[N], Next[N], deg[N],tot=0;
struct EDGE
{
    int u, v;
}edge[N];

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin >> n >> m >> k){
        tot = 0;
        memset(deg, 0, sizeof(deg));
        cin >> l >> r;
        rep(i,1,k+1){
            int u, v;
            cin >> u >> v;
            v += n;
            edge[tot].u = u;
            edge[tot].v = v;
            tot++;
            deg[u]++, deg[v]++;
        }
        rep(e,0,tot){
            int u = edge[e].u;
            int v = edge[e].v;
            if(deg[u]>r || deg[v]>r){
                deg[u]--;
                deg[v]--;
            }
        }

        bool flag = true;

        rep(i,1,n+m+1){
            if(deg[i]<l || deg[i]>r){
                flag = false;
                break;
            }
        }
        cout << "Case: "<<Cas++<<": ";
        if(flag)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}

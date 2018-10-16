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
VI son[10010];
int f[10010][2], v[10010], h[10010], n;
void dp(int x)
{
    f[x][0] = 0;
    f[x][1] = h[x];
    rep(i,0,son[x].size()) {
        int y = son[x][i];
        dp(y);
        f[x][0] += max(f[y][1], f[y][0]);
        f[x][1] += f[y][0];
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin >> n)
    {
        rep(i, 0, n + 1) son[i].clear();
        rep(i, 1, n + 1) cin >> h[i];
        int x, y;
        rep(i,1,n) {
            cin >> x >> y;
            v[x] = 1;
            son[y].pb(x);
        }
        cin >> x >> y;
        int root;
        rep(i,1,n+1) {
            if(!v[i]) {
                root = i;
                break;
            }
        }
        dp(root);
        cout << max(f[root][0], f[root][1]) << endl;
        memset(v, 0, sizeof(v));
    }
    return 0;
}
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
VI son[N];
int f[N][2], v[N], h[N],m, n;
void dp(int x)
{
    f[x][0] = 0;
    rep(i,0,son[x].size()) {
        int y = son[x][i];
        dp(y);
        per(t,0,m+1){
            per(j,0,t+1){
                if(t-j>=0){
                    f[x][t] = max(f[x][t], f[x][t - j] + f[y][j]);
                }
            }
        }
    }
    if(x!=0) per(t,0,m+1) {
            f[x][t] = f[x][t - 1] + h[x];
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin >> n>>m)
    {
        rep(i, 0, n + 1) son[i].clear();
        rep(i,1,n+1) {
            int x, y;
            cin >> x >> y;
            x++;
            h[i] = y;
            son[x].pb(i);
        }
        int root;
        rep(i,1,n+1) {
            if(!v[i]) {
                root = i;
                break;
            }
        }
        dp(0);
        int ans = 0;
        rep(i,1,n+1){
            ans = max(ans, f[0][i+1]);
        }
        cout << ans << endl;
    }
    return 0;
}
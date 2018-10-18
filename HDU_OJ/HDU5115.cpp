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
int T,n,m;
int f[N][N];
int a[N], b[N];
int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (cin>>T; T;T--){
        cin >> n;
        rep(i, 0, n + 5) rep(j, 0, n + 5) f[i][j] = 0;
        rep(i,1,n+1){
            cin >> a[i];
        }
        rep(i,1,n+1){
            cin >> b[i];
        }
        rep(i,1,n+1)rep(l,1,n-i+1+1){
            int r = i + l - 1;
            f[l][r] = 0x3f3f3f3f;
            rep(k,l,r+1){
                f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r] + a[k] + b[l - 1] + b[r + 1]);
            }
        }
        cout << "Case #" << ++m << ": " << f[1][n] << "\n";
    }
    return 0;
}
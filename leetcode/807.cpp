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
int grid[N][N];
int row[N], col[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i,1,n+1) rep(j,1,n+1) {
        cin >> grid[i][j];
    }
    rep(i,1,n+1) rep(j,1,n+1) {
        row[i] = max(row[i], grid[i][j]);
        col[i] = max(col[i], grid[j][i]);
    }
    rep(i,1,n+1) rep(j,1,n+1) {
        grid[i][j] = min(row[i], col[j]);
    }
    rep(i,1,n+1) rep(j,1,n+1) {
        printf("%d%c", grid[i][j], j==n?'\n':' ');
    }
    return 0;
}
/*
3 0 8 4
2 4 5 7
9 2 6 3
0 3 1 0

*/
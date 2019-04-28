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
int a[10][N];
int cur[N];
int clen;
int c[N][N];
int path[N][N];

void dfs(int k, int i, int j, int len)
{
    if(i==0 || j==0){
        return;
    }
    if(path[i][j] == 0){
        dfs(k, i - 1, j - 1, len);
        printf("%d=", a[k][j - 1]);
    }
    else if(path[i][j] == 1) {
        dfs(k, i - 1, j, len);
    }
    else {
        dfs(k, i, j - 1, len);
    }

    clen = max(clen, len);
}

// len = n;
int Lcs(int k)
{
    memset(c, 0, sizeof(c));
    memset(path, 0, sizeof(path));
    rep(i,1,clen+1){
        rep(j,1,n+1){
            if(cur[i - 1] == a[k][j - 1]){
                c[i][j] = c[i - 1][j - 1] + 1;
                path[i][j] = 0;
            }
            else if(c[i - 1][j] > c[i][j - 1]){
                c[i][j] = c[i - 1][j];
                path[i][j] = 1;
            }
            else {
                c[i][j] = c[i][j - 1];
                path[i][j] = -1;
            }
        }
    }
    clen = 0;
    dfs(k,n,n,1);
    // printf("::\n%d\n", clen);
    return c[n][n];
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i,1,m+1){
        rep(j,1,n+1){
            cin >> a[i][j];
            if(i == 1)
                cur[j] = a[i][j];
        }
    }

    int ans = 0;
    clen = n;
    rep(i,2,m+1){
        ans = Lcs(i);
        printf("ans:%d\n", ans);
    }

    return 0;
}
/*

*/

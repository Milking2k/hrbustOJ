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
int T,n,m,ans=0;
char a[107][107];
bool vis[107][107];
int dirx[10] = {0, 0, 1, 0, -1, 1, 1, -1, -1};
int diry[10] = {0, 1, 0, -1, 0, 1, -1, 1, -1};
void dfs(int x, int y)
{
    // printf("x:%d y:%d\n", x, y);
    vis[x][y] = 1;
    rep(i,1,8+1){
        int nowx = x + dirx[i];
        int nowy = y + diry[i];
        if(nowx<1 || nowx>n || nowy<1 || nowy >m || vis[nowx][nowy] || a[nowx][nowy]!='#')
            continue;
        dfs(nowx, nowy);
    }
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i,1,n+1){
        rep(j,1,m+1){
            cin >> a[i][j];
        }
    }
    ans = 0;
    memset(vis, 0, sizeof(vis));
    rep(i,1,n+1){
        rep(j,1,m+1){
            if(!vis[i][j] && a[i][j]=='#'){
                dfs(i, j);
                ans++;
                // printf("ij::%d %d %d\n",i,j, ans);
            }
            // system("pause");
        }
    }
    cout << ans << endl;
    return 0;
}
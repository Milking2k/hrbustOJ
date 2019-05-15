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
int T,n,m;
int a[3][30];

map<string, int> mm;
int ans;
int dirx[10] = {1, 0, -1};
int diry[10] = {1, 0, -1};
void dfs(int x, int ii, int jj)
{
    // printf("%d %d\n", ii, jj);
    if(ii == 1 && jj == x - 1) {
        string ss;
        ss.clear();
        rep(i,0,2){
            rep(j,0,6){
                ss += (a[i][j] + '0');
            }
            ss += '\n';
        }
        cout <<ss << endl;
        if(mm[ss] >= 1) {
            return;
        }
        else {
            mm[ss] = 1;
            ans++;
            return;
        }
    }
    for (int i = 0; i < 3; ++i) {
        rep(j, 0, 3) {
            int dx = ii + dirx[i];
            int dy = jj + dirx[j];
            if((dx ==0 && dy==0) || dx < 0 || dy < 0 || dx > 1 || dy >= x || a[dx][dy] == 1)
                continue;
            a[dx][dy] = 1;
            dfs(x, dx, dy);
            a[dx][dy] = 0;
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    if(n==0){
        printf("0\n");
    }
    else if(n == 1){
        printf("1\n");
    }
    else if(n == 2) {
        printf("4\n");
    }
    else {
        ll ans = 4*powmod(3, n - 2, 1000000007);
        printf("%lld\n", ans % mod);
    }
    // rep(i,1,20){
        // mm.clear();
        // ans = 0;
        // memset(a, 0, sizeof(a));
        // dfs(5, 0, 0);
        // printf("%d\n", ans);
    // }

    return 0;
}
/*



*/
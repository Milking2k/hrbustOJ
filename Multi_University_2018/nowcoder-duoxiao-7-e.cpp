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

const int N = 2e5+7;
int n,m,k,x;
int dp[6][N];
int w[110];
VI sz;

void solve(int d, int t)
{
    if(d==0) return ;
    rep(j,0,x+1)if(dp[d-1][t-w[j]]){
        sz.pb(j);
        solve(d-1, t-w[j]);
        return ;
    }
}


int main()
{
    scanf("%d",&k);
    x = -1;
    rep(i,1,71) if(i*(i-1)*(i-2)*(i-3)/24 <= k) x = i;

    k -= x*(x-1)*(x-2)*(x-3)/24;
    dp[0][0] = 1;
    rep(j,0,x+1) w[j] = j*(j-1)*(j-2)/6;
    rep(i,0,5) rep(k,0,100001) if(dp[i][k]){
        rep(j,0,x+1) if(k + w[j] <= 1e5) dp[i+1][k+w[j]] = 1;
    }
    solve(5,k);
    vector<PII> ans;
    rep(i,0,x) rep(j,i+1,x) ans.pb(mp(i,j));
    rep(i,0,SZ(sz)) rep(j,0,sz[i]) ans.pb(mp(j,i+x));
    printf("%d %d\n",x+5,SZ(ans));
    for(auto cnt:ans){
        printf("%d %d\n",cnt.fi+1,cnt.se+1);
    }




    return 0;
}

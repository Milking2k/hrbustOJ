<<<<<<< HEAD
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
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e2+7;
int T,n,m,p;
double dp[N][N],c[N][N],pw[N];

void init()
{
    pw[0] = c[0][0] = 1;
    rep(i,1,N){
        pw[i] = pw[i-1]/2;
        c[i][0] = 1;
    }
    rep(i,1,N){
        rep(j,1,i+1){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
}

int main()
{
    init();

    for(read(T);T;T--){
        read(n),read(m),read(p);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        rep(i,1,m+1) rep(j,0,n+1) for(int k = max(0, j-p); k<=j+p && k<=n; k++){
            if(n-k >=p && k<=j) dp[i][j] += dp[i-1][k]*c[p][j-k]*pw[p];
            else dp[i][j] += dp[i-1][k]*c[p][n-j]*pw[p];
        }
        
        double ans = 0;
        rep(i,1,n+1) ans += dp[m][i]*i;

        printf("%.3f\n",ans);
    }

    return 0;
=======
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
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e2+7;
int T,n,m,p;
double dp[N][N],c[N][N],pw[N];

void init()
{
    pw[0] = c[0][0] = 1;
    rep(i,1,N){
        pw[i] = pw[i-1]/2;
        c[i][0] = 1;
    }
    rep(i,1,N){
        rep(j,1,i+1){
            c[i][j] = c[i-1][j] + c[i-1][j-1];
        }
    }
}

int main()
{
    init();

    for(read(T);T;T--){
        read(n),read(m),read(p);
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        rep(i,1,m+1) rep(j,0,n+1) for(int k = max(0, j-p); k<=j+p && k<=n; k++){
            if(n-k >=p && k<=j) dp[i][j] += dp[i-1][k]*c[p][j-k]*pw[p];
            else dp[i][j] += dp[i-1][k]*c[p][n-j]*pw[p];
        }
        
        double ans = 0;
        rep(i,1,n+1) ans += dp[m][i]*i;

        printf("%.3f\n",ans);
    }

    return 0;
>>>>>>> d2d85486aa24dc4cfd0bd17c48ed9f6c990960c3
}
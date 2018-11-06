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
ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
// head
const int N = 5e2+7;
const int M = 1e4 + 7;

int T,n,m,cnt;

bool vis[M];
int prime[M];

void getPrime()
{
    cnt = 0;
    rep(i,2,M-5){
        if(!vis[i])
            prime[++cnt] = i;
        for (int j = 1; i * prime[j] < M - 5;j++){
            vis[i * prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}

ll ans[M][M];

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    getPrime();
    scanf("%d", &n);
    if(n==2){
        printf("4 7\n23 10\n");
        return 0;
    }
    rep(i, 0, n + 2) rep(j, 0, n + 2) ans[i][j] = 1;
    rep(i,1,n+1){
        rep(j,1,n+1){
            if((i&1)==(j&1)){
                ans[i][j] = prime[(i + j) / 2] * prime[(i + n + 1 - j) / 2 + n];
                ans[i + 1][j] = lcm(ans[i + 1][j], ans[i][j]);
                ans[i - 1][j] = lcm(ans[i - 1][j], ans[i][j]);
                ans[i][j + 1] = lcm(ans[i][j + 1], ans[i][j]);
                ans[i][j - 1] = lcm(ans[i][j - 1], ans[i][j]);
            }
        }
    }
    rep(i,1,n+1)rep(j,1,n+1){
        if((i&1)!=(j&1)){
            printf("%lld", ans[i][j] + 1);
        }
        else{
            printf("%lld", ans[i][j]);
        }
        printf(j == n ? "\n" : " ");
    }
    return 0;
}
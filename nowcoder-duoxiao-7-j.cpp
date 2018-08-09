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

const int N = 1e3+7;

int n,m,k,lmax[N][N],umax[N][N],len[60],pos[200];
char s[N][N];

void solve()
{
    ll ans = 0;
    rep(i,1,n+1){
        memset(pos,0,sizeof(pos));
        rep(j,1,m+1){
            lmax[i][j] = min(lmax[i][j-1] + 1, j - pos[s[i][j]]);
            pos[s[i][j]] = j;
        }
    }
    rep(j,1,m+1){
        memset(pos,0,sizeof(pos));
        rep(i,1,n+1){
            umax[i][j] = min(umax[i-1][j] + 1, i - pos[s[i][j]]);
            pos[s[i][j]] = i;
        }
    }

    rep(r,1,m+1){
        memset(len, 0, sizeof(len));
        rep(d,1,n+1){
            rep(i,0,lmax[d][r]){
                len[i] = min(len[i]+1, umax[d][r-i]);
                if(i) len[i] = min(len[i], len[i-1]);
                ans += len[i];
            }
            rep(i,lmax[d][r],55){
                len[i] = 0;
            }
        }
    }
    printf("%lld\n",ans);
}


int main()
{
    scanf("%d %d",&n,&m);
    rep(i,1,n+1) scanf("%s",s[i]+1);

    solve();
    return 0;
}

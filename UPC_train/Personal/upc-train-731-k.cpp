#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

inline void overtack(int &x,const int &y){if(x>y)x=y;}
const int MAXN = 1100;
const int MAXV = 5100;
const int INF = 0x3f3f3f3f;

int n;
struct edge{int y,next;} a[MAXN<<1];
int len,head[MAXN];

inline void ins(const int x,const int y){a[++len]=(edge){y,head[x]};head[x]=len;}

int f[MAXN],h[MAXN],dp[2][MAXV];
void init(const int now){for(int i=0;i<MAXV;i++) dp[now][i]=INF;}

bool dp_fc(const int x)
{
    if(!head[x]){
        f[x]=0;
        return true;
    }
    for(int k=head[x],y=a[k].y;k;k=a[k].next,y=a[k].y)
        if(!dp_fc(y))
            return false;

    int now=1;
    init(now);
    dp[now][0]=0;
    for(int k=head[x],y=a[k].y; k; k=a[k].next,y=a[k].y)
    {
        now=!now;
        init(now);

        for(int i=0; i<=h[x];i++)
        {
            if(i>=h[y]) overtack(dp[now][i], dp[!now][i-h[y]]+f[y]);
            if(i>=f[y]) overtack(dp[now][i], dp[!now][i-f[y]]+h[y]);
        }
    }

    int cc=INF;
    for(int i=0;i<=h[x];i++)
        overtack(cc, dp[now][i]);

    if(cc==INF) return false;
    f[x]=cc;

    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        int x;
        scanf("%d",&x);
        ins(x,i);
    }

    for(int i=1;i<=n;i++)
        scanf("%d",&h[i]);

    printf(dp_fc(1)?"POSSIBLE":"IMPOSSIBLE");

    return 0;
}

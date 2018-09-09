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
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head


unsigned X,Y,Z;
unsigned rng61()
{
    X = X^(X<<11);
    X = X^(X>>4);
    X = X^(X<<5);
    X = X^(X>>14);
    unsigned W = X^(Y^Z);
    X = Y;
    Y = Z;
    Z = W;
    return Z;
}

const int N = 1E5+7;

int n,m,a[N],b[20][N],Log[N];

void Update(int l, int r, int z)
{
    int k = Log[r-l+1];
    b[k][l] = max(b[k][l], z);
    b[k][r-(1<<k)+1] = max(b[k][r-(1<<k)+1], z);
}

void solve()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> m >> X >> Y >> Z;
    for(int j=0;j<20;j++)
        for(int i=1;i<=n;i++)
            b[j][i]=0;
    rep(i,1,m+1){
        int x = rng61()%n+1;
        int y = rng61()%n+1;
        int z = rng61()%(1<<30);

        Update(min(x,y), max(x,y), z);
    }

    for(int j=19;j;j--){
        for(int i=1;i+(1<<j)-1 <= n; i++){
            b[j-1][i] = max(b[j-1][i], b[j][i]);
//            b[j-1][i] = max(b[j-1][i],b[j][i]);
//            b[j-1][i+(1<<j-1)] = max(b[j-1][i+(1<<j-1)], b[j][i]);
            b[j-1][i+(1<<j-1)] = max(b[j-1][i+(1<<j-1)],b[j][i]);
        }
    }

    ll ans=0;
    rep(i,1,n+1){
        ans = ans^(i*(long long)b[0][i]);
    }
    cout << ans << endl;


}

int main()
{
    Log[2] = 1;
    rep(i,3,N){
        Log[i] = Log[i>>1]+1;
    }

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}


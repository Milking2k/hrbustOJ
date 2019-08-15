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
const int N = 1e6+7;
int T,n,m;
int solve(vector<int> &prices)
{
    int b1 = -0x3f3f3f3f, b2 = -0x3f3f3f3f;
    int c1 = 0, c2 = 0;
    for (int &price : prices) {
        b1 = max( b1, -price );
        c1 = max( c1, b1 + price );
        b2 = max( b2, c1 - price );
        c2 = max( c2, b2 + price );
    }
    return c2;
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    scanf("%d",&n);
    vector<int> prices(n,0);
    rep(i,0,n) cin >> prices[i];
    printf("%d", solve(prices));

    return 0;
}
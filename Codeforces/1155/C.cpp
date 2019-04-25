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
ll ans = 0;
ll a[N],b[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;

    if(n <= 2){
        ll x, y;
        cin >> x >> y;
        rep(i,1,m+1){
            ll cur;
            cin >> cur;
        }
    }

    ll minans = 0x3f3f3f3f3f3f3f3f;
    rep(i,2,n+1) {
        cin >> a[i];
        b[i - 1] = a[i] - a[i - 1];
        // printf("%lld\n", b[i - 1]);
        if(i > 2) {
            ans = gcd(ans, b[i - 1]);
            minans = min(minans, b[i - 1]);
        }
    }

    ll ans2 = 0;
    rep(i, 1, n + 1){
        ans2 = gcd(ans2, b[i] / ans);
    }

    rep(i,1,m+1) {
        ll x;
        cin >> x;
        // printf("ddd:%lld %lld\n", ans2, b[i] / ans);
        if(x % ans == 0 && x/ans <= ans2){
            printf("YES\n");
            printf("%lld %d\n", a[1], i);
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}
/*

*/
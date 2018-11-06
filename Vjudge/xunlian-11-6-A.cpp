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
ll a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int pos = 0;
    cin >> n >> m;
    rep(i,1,n+1){
        cin >> a[i];
        if(a[i]>0 && pos==0)
            pos = i-1;
    }
    // printf("pos:%d \n", pos);
    int l, r;
    if(pos >= m){
        l = pos - m+1;
        r = pos;
    }
    else{
        l = 1;
        r = m;
    }
    ll ans = 0x3f3f3f3f3f3f3f3fll;
    rep(i,l,n-m+2){
        // printf("%d %d\n", i, i+m-1);
        ans = min(ans, abs(a[i + m - 1]) + abs(min(0ll,a[i])) + min(abs(a[i + m - 1]), abs(min(0ll,a[i]))));
    }
    printf("%lld\n", ans);
    return 0;
}
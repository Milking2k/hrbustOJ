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
PII a[N], b[N];
int cnt[4];
bool cmp(PII a, PII b){
    if(a.se==b.se){
        return a.fi > b.fi;
    }
    return a.se > b.se;
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    int x;
    rep(i,0,N){
        a[i].fi = i, b[i].fi = i;
        a[i].se = 0, b[i].se = 0;
    }
    rep(i,1,n+1){
        scanf("%d", &x);
        if(i&1){
            a[x].se++;
        }
        else{
            b[x].se++;
        }
    }
    sort(a, a + N, cmp );
    sort(b, b + N, cmp );
    if(a[0].fi==b[0].fi){
        printf("%d\n", min(n - a[1].se - b[0].se, n - a[0].se - b[1].se));
    }
    else
        printf("%d\n", n - a[0].se - b[0].se);
    return 0;
}
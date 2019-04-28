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
int a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    ll tot = m * (m + 1) / 2;
    ll adtot = 0;
    rep(i, 1, m + 1) {
        a[i] = i;
    }
    ll sub = n - tot;
    // if(sub < 0) {
    //     puts("NO");
    //     return 0;
    // }

    adtot = sub / m;
    sub -= adtot * m;
    ll checksum = 0;
    rep(i,1,m+1){
        int t = m - i + 1;
        a[i] += adtot;
        if(i > 1 && a[i] < 2*a[i-1]){
            // printf("%lld;%d;", sub, t);
            int temp = sub / t;
            int mxm = min(2 * a[i - 1] - a[i], temp);
            // printf("%d::%d::\n", temp, 2 * a[i - 1] - a[i]);
            sub -= t * mxm;
            a[i] += mxm;
            adtot += mxm;
        }
        checksum += a[i];
    }

    if(checksum != n){
        puts("NO");
        return 0;
    }

    puts("YES");

    rep(i,1,m+1){
        printf("%d ", a[i]);
    }
    return 0;
}
/*

*/
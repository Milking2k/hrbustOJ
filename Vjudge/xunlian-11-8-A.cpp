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
const int N = 2e5+7;
int T,n,m;
ll a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(~scanf("%d",&n))
    {
        rep(i,1,n+1){
            ll x;
            scanf("%lld", &x);
            a[i] = x-i;
        }
        sort(a + 1, a + 1 + n);
        ll b = a[n / 2+1];
        if(n&1==0) {
            b = (b + a[n / 2]) / 2;
        }

        // printf("b:%d\n", b);
        ll ans = 0;
        rep(i,1,n+1){
            ans += abs(a[i] - b);
        }
        printf("%lld\n", ans);
    }
    return 0;
}

/*

2 2 3 5 5
1 0 0 1 0

6 5 4  3  2  1
5 3 1 -1 -3 -5
5 3 1 1 3 5 = 18

1  1  1  1  2  3  4
0 -1 -2 -3 -3 -3 -3
3 2  1 0 0 0 0

*/
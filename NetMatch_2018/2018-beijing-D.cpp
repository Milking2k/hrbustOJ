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
const int N = 2e6+7;
int T, n;
ll m;
int a[N],b[N];
int pre[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    for (scanf("%d", &T); T;T--){
        scanf("%d%lld", &n, &m);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(pre, 0, sizeof(pre));

        rep(i, 1, n + 1) scanf("%d", a + i);
        rep(i, 1, n + 1) scanf("%d", b + i);

        rep(i, 1, n + 1) pre[i] = pre[n + i] = a[i] - b[i];

        int l = 1, r = 1;
        while(l<=n && r-l+1<=n){
            m += pre[r];
            r++;
            while(m<0){
                m -= pre[l];
                l++;
            }
        }
        printf(l > n ? "-1\n" : "%d\n", l);

    }
        return 0;
}
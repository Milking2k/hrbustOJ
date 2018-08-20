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
const int INF = 0x3f3f3f3f;
int T,n,m;
int a[N],b[N];
bool v2[N],v[N];

int main()
{
    read(n);
    rep(i,1,n+1) read(a[i]);
    rep(i,1,n+1) read(b[i]);

    ll ans = 0;
    memset(v,false,sizeof(v));
    memset(v2,false,sizeof(v2));
    rep(i,1,n+1){
        if(v[i]) continue;
        int now = i;
        while(!v2[now]){
            if(v[now]) break;
            v2[now] = true;
            now = b[now];
        }
        if(!v[now]){
            int t = now;
            int MM = a[t];
            t = b[t];
            while(t!=now){
                MM = min(MM, a[t]);
                t = b[t];
            }
            ans += MM;
        }
        now = i;
        while(!v[now]){
            v[now] = true;
            now = b[now];
        }
    }
    printf("%lld\n",ans);

    return 0;
}

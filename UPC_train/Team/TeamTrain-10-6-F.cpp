#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i = (a); i<(n); i++)
#define per(i,a,n) for (int i = (n)-1; i>=(a); i--)
#define pb push_back
#define mp make_pair
#define all(now) (now).begin(),(now).end()
#define fi first
#define se second
#define SZ(now) ((int)(now).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e6+7;
const ll M = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-8;
int T, n, m, k;

ll fenmu(int mid){
    ll res = n;
    rep(i,n+1,mid+n+1){
        res = res * i;
        if(res>M){
            return -1;
        }
    }
    return res;
}
double f(int mid)
{
    ll res = fenmu(mid+n);
    printf("ans:%lld\n", res);
    return m * mid * n * 1.0 / res;
}

int SanFen(int l,int r)
{
    while(l < r-1)
    {
        int mid= (l+r)/2;
        int mmid = (mid+r)/2;
        
        if(fenmu(mid)==-1 || fenmu(mmid)==-1 || f(mid) > f(mmid) )
            r = mmid;
        else
            l = mid;
    }
    return f(l) > f(r) ? l : r;
}
int main()
{
    while(~scanf("%d%d",&n,&m)){

        int ans = SanFen(1, N);
        printf("%.7f\n", f(ans));
    }
    return 0;
}
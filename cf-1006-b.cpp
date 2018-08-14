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
inline int read(){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return x*f;}
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 2e3+7;
PII a[N],b[N];
int T,n,m,k;
int main()
{
    n = read();
    k = read();
    rep(i,1,n+1){
        int x = read();
        a[i] = mp(x,i);
    }
    sort(a+1,a+1+n);
//    rep(i,1,n+1){
//        printf("%d ",a[i].fi);
//    }puts("");

    ll sum = 0;
    rep(i,1,k+1){
        sum += a[n-i+1].fi;
        b[i].fi = a[n-i+1].se;
        b[i].se = a[n-i+1].fi;
    }

    sort(b+1,b+1+k);

    int cnt=1;
    printf("%lld\n",sum);
    rep(i,1,k+1){
        if(i==k)
            printf("%d\n",n-cnt+1);
        else
            printf("%d ",b[i].fi-cnt+1);
        cnt = b[i].fi+1;
    }

    return 0;
}

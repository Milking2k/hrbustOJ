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

const int N = 2e5+7;
int a[N];
ll pre[N],lst[N];
int T,n,m,k;
int main()
{
    n = read();
    rep(i,1,n+1){
        a[i] = read();
    }
    rep(i,1,n+1){
        pre[i] = pre[i-1] + a[i];
        lst[n-i+1] = lst[n-i+1+1] + a[n-i+1];
    }

    int l=1,r=n;
    ll ans=0;
    while(l<r){
//            printf("lr::%d %d\n",l,r);
        while(l<r && pre[l] < lst[r]) l++;
        while(l<r && pre[l] > lst[r]) r--;

        if(pre[l] == lst[r]) ans = max(ans, pre[l]),r--,l++;
    }
    printf("%lld\n",ans);
    return 0;
}


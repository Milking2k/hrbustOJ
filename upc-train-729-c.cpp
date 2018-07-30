#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 5e3+7;
int t,n,m;
int h[N],dp[N][N];
bool check(int u,int v,int w)
{
    return (1LL*(v-u)*(h[w]-h[u])-1LL*(w-u)*(h[v]-h[u])) > 0;
}

int getdp(int l, int r){
    return l>r ? 0 : dp[l][r];
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n+1) {
        scanf("%d",&h[i]);
    }
    ll ans=0;
    rep(r,1,n+1){
        int flag=r, cur=1;// 单个区间中的右端点一定会有守卫
        dp[r][r]=1;
        per(l,1,r){
            if(flag == r || check(l,flag,r)){
                cur += min(getdp(l+1, flag-1), getdp(l+1,flag));
                flag = l;
            }
            dp[l][r] = cur + min(getdp(l,flag-1), getdp(l,flag));
        }
        rep(l,1,r) ans^=dp[l][r];
    }
    if(n&1) ans^=1;

    printf("%lld",ans);
    return 0;
}

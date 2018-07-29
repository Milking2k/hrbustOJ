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

const int N = 1E5+7;
int t,n,m,ans,emt[N];
ll X,k,q;
int sign=-1;
int nowt,nowai;
struct node
{
    int t,ai;
}qse[N];

ll toans(ll k){
    return max(min(k, X),0);
}
void solve(){
    int j=1;
    ll maxnum=X,minnum=0,tot=0;
    scanf("%d",&q);

    rep(i,1,q+1){
        scanf("%d %d",&nowt,&nowai);
        for(;j<=k;j++){
            if(emt[j] > nowt) break;
            ll cnt = sign*(emt[j]-emt[j-1]);
//            printf("cnt:%lld\n",cnt);
            tot += cnt;
            maxnum = toans(cnt+maxnum);
            minnum = toans(cnt+minnum);
            sign *= -1;
        }
//        printf("max:%lld min:%lld\n",maxnum,minnum);
        ll nowans = nowai + tot;
//        printf("nowh:%lld\n",nowh);
        nowans = min(max(nowans,minnum),maxnum);
//        printf("nowans:%lld\n",nowans);
        nowans = toans((nowt-emt[j-1])*sign + nowans);

        printf("%lld\n", nowans);
    }
}

int main()
{
    scanf("%lld%lld",&X,&k);
    rep(i,1,k+1){
        int cnt=0;
        scanf("%d", &cnt);
        emt[i] = cnt /*- emt[i-1]*/;
    }
    solve();
    return 0;
}


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

const int N = 10+7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int T;
ll val[]={0,1,5,10,20,50,100,200,500,1000,2000};
ll p,ans,c[17];

void dfs(int cur, ll price, ll resNum)//硬币种类，还需要减的钱，已减硬币数量
{
    if(price<0) return;
    if(cur==0){
        if(price==0)ans = min(ans, resNum);
        return;
    }
    ll tmp = min(c[cur], price / val[cur]);
    dfs(cur - 1, price - tmp * val[cur], resNum + tmp);

    if(tmp)
        dfs(cur - 1, price - (tmp - 1) * val[cur], resNum + tmp - 1);
}
int main()
{
    for (scanf("%d", &T); T; T--){
        ll tot = 0, sumPrice = 0;
        ans = INF;

        scanf("%lld", &p);
        rep(i,1,11){
            scanf("%lld",&c[i]);
            tot += c[i];
            sumPrice += val[i] * c[i];
        }

        if(sumPrice<p){
            printf("-1\n");
        }
        else{
            dfs(10, sumPrice-p, 0);
            if(ans==INF)printf("-1\n");
            else printf("%lld\n",tot-ans);
        }
    }
    return 0;
}

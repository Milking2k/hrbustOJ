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
const ll mod = 998244353;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N = 1e5+7;
int T,n,m;
double a,b,c,d;
int main()
{
    for(read(T);T;T--){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        double k1 = a/b;
        double k2 = c/d;
        if(k1 == k2) {
            printf("-1\n");
            continue;
        }
        if(k1 > k2){
            swap(k1,k2);
        }

        ll ans=0;
        ll l=1,r=1e18,mid=l,up,down;
        ll pos1=1;
        while(l<r){
            mid = (l+r)>>1;
            up = (ll)ceil(k2*mid);
            down = (ll)floor(k1*mid);
            if(up >= down) break;
            if( up < down  ) r = mid-1;
            else l = mid+1;
//            puts("1");
        }
        printf("mid:%lld\n",mid);
        pos1 = mid;
        if((down - k2*mid) < 1e-6){
            ans  = ((mid-1)+down)%mod;
        }
        else{
            ans = ((mid-1)+(down-1))%mod;
        }

        l=1,r=1e18,mid = l,up,down;
        ll pos=l;
        while(l<r){
            mid = (l+r)>>1;
            down = (ll)floor(k1*mid);
            double cnt = (k2*mid);

            if(down > cnt &&  down > k2*(mid+1)){
                pos = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        ans = (ans+abs(pos - pos1) + 2*mod)%mod;
        printf("%lld\n",ans%mod);
    }

    return 0;
}

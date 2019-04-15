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
const int N = 1e5+7;
int T,n,m;
PII a[N];

int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(cin >> n){
        int h, m;
        rep(i,1,n+1) {
            scanf("%d:%d", &a[i].fi, &a[i].se);
        }
        int flagans = false;
        rep(te,1,n+1) {
            if(flagans)
                break;
            if(a[te].fi > 6 && a[te].fi < 10 || (a[te].fi==6 && a[te].se >= 30) || (a[te].fi == 10 && a[te].se == 0)) {
                per(j,te,n+1){
                    if(a[j].fi > 6 && a[j].fi < 16 || (a[j].fi==6 && a[j].se >= 30) || (a[j].fi == 16 && a[j].se == 0)) {
                        puts("24000");
                        flagans = 1;
                    }
                    else if(a[j].fi > 16 && a[j].fi < 19 || (a[j].fi==16 && a[j].se >= 1) || (a[j].fi == 19 && a[j].se == 0)) {
                        puts("36000");
                        flagans = 1;
                    }
                    if(flagans)
                        break;
                }
            }
            else if(a[te].fi > 10 && a[te].fi < 16 || (a[te].fi==10 && a[te].se >= 1) || (a[te].fi == 16 && a[te].se == 0)) {
                per(j,te,n+1){
                    if(a[j].fi > 10 && a[j].fi < 16 || (a[j].fi==10 && a[j].se >= 1) || (a[j].fi == 16 && a[j].se == 0)) {
                        puts("16800");
                        flagans = 1;
                    }
                    if(flagans)
                        break;
                }
            }
            else if(a[te].fi > 10 && a[te].fi < 19 || (a[te].fi==10 && a[te].se >= 1) || (a[te].fi == 19 && a[te].se == 0)) {
                per(j,te,n+1){
                    if(a[j].fi > 10 && a[j].fi < 16 || (a[j].fi==10 && a[j].se >= 1) || (a[j].fi == 16 && a[j].se == 0)) {
                        puts("24000");
                        flagans = 1;
                    }
                    if(flagans)
                        break;
                }
            }
        }
    }
    return 0;
}
/*

*/
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

const int N = 2e3+7;
int T, n, m, k;
int a[N][N];
int main()
{
    for (scanf("%d", &T); T;T--){
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        ll sum = 0,sum2=0;
        rep(i,1,n+1){
            rep(j,1,m+1){
                scanf("%d", &a[i][j]);
                if(a[i][j]>0)sum++;
                if(a[i][j]>1)sum2+=(a[i][j]-1);
            }
        }
        ll sub = 0;
        rep(i,1,n+1){
            rep(j,1,m+1){
                if(a[i][j]>0 && a[i][j+1]>0){
                    sub+=min(a[i][j],a[i][j+1]);
                    // printf("ij:%d %d\n", i, j);
                }
                if(a[i][j]>0 && a[i+1][j]>0){
                    sub+=min(a[i][j],a[i+1][j]);
                    // printf("ij:%d %d\n", i, j);
                }
            }
        }
        // printf("sss:%d %d %d\n", sum, sum2, sub);
        printf("%lld\n", 5*sum + 4 * sum2 - 2*sub);
    }
    return 0;
}
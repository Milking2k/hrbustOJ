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
const double PI = acos(-1);
int T,n,cnt;
int a[N];
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while(~scanf("%d%d",&n,&cnt))
    {
        rep(i,1,n+1){
            scanf("%d", a + i);
        }
        // sort(a + 1, a + n + 1);
        double sum = 0;
        double m = cnt;
        // if(a[n]>180){
        //     a[n] = 360 - 180;
        //     sum -= 1.0 * m * m * sin(a[n]*PI/180)/2;
        // }
        // else{
        //     sum += 1.0 * m * m * sin(a[n]*PI/180)/2;
        // }
        // printf("%.3f\n", sin(PI/2));
        rep(i,1,n+1){
            sum += 1.0 * m * m * sin(a[i]*PI/180)/2;
        }
        if(sum<1e-3)
            sum = 0;
        printf("%.3f\n", sum);
    }
    return 0;
}
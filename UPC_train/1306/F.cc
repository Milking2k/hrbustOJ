// #include <bits/stdc++.h>
// using namespace std;
// #define rep(i,a,n) for (int i = a; i<n; i++)
// #define per(i,a,n) for (int i = n-1; i>=a; i--)
// #define pb push_back
// #define mp make_pair
// #define all(now) (now).begin(),(now).end()
// #define fi first
// #define se second
// #define SZ(now) ((int)(now).size())
// typedef vector<int> VI;
// typedef long long ll;
// typedef pair<int,int> PII;
// const ll mod = 1000000007;
// inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
// ll powmod(ll a,ll b,ll mod) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
// ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// // head
// const int N = 1e5+7;
// int T,n,m;
// const double R = 6371.0;
// const double eps = 1e-10;
// const double PI = acos(-1.0);
// double solve(double lat1, double lng1, double lat2, double lng2)
// {
//     // if(lat1+eps < 0) lat1 = fabs(lat1) + 180.0;
//     // if(lat2+eps < 0) lat2 = fabs(lat2) + 180.0;
//     lat1 = lat1 * PI / 180.0;
//     lat2 = lat2 * PI / 180.0;
//     lng1 = lng1 * PI / 180.0;
//     lng2 = lng2 * PI / 180.0;
//     if(fabs(lat1 - lat2) < eps)
//         return R * cos(lat1) * min(fabs(lng1 - lng2), 2 * PI * fabs(lng1 - lng2));
//     double x = R * cos(lat1) * cos(lng1) - R * cos(lat2) * cos(lng2);
//     double y = R * cos(lat1) * sin(lng1) - R * cos(lat2) * sin(lng2);
//     double z = R * sin(lat1) - R * sin(lat2);
 
//     double ab = sqrt(x * x + y * y + z * z);
//     double tm = 2.0 * asin(ab / (2.0 * R));
//     double ans = tm * R;
 
//     return ans;
// }
// int main()
// {
//     //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
//     cin >> T;
//     while(T--) {
//         double a, b, c, d;
//         cin >> a >> b >> c >> d;
//         double ans2 = solve(a, b, a, d) + solve(a, d, c, d);
//         // printf("%.7f::%.7f\n", solve(a, b, a, d), solve(a, d, c, d));
//         printf("%.10f %.10f\n",solve(a, b, c, d), ans2);
//     }
//     return 0;
// }
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
int a[N];
const double R = 6371.0;
double eps = 1e-10;
double PI = acos(-1.0);
double a2r(double tangle){
    return tangle / 180.0 * PI;
}
double solve1(double aw,double aj,double bw, double bj)
{
    aw = a2r(aw);
    aj = a2r(aj);
    bw = a2r(bw);
    bj = a2r(bj);
    if(fabs(aw - bw) < 1e-10)
        return R * cos(aw) * min(fabs(aj - bj), 2 * PI * fabs(aj - bj));
    return R * acos(cos(aw) * cos(bw) * cos(aj - bj) + sin(aw) * sin(bw));
}
// double solve(double lat1, double lng1, double lat2, double lng2)
// {
//     if(lng1 < eps) lng1 = fabs(lng1) + 180.0;
//     if(lng2 < eps) lng2 = fabs(lng2) + 180.0;
//     lat1 = lat1 * PI / 180.0;
//     lat2 = lat2 * PI / 180.0;
//     lng1 = lng1 * PI / 180.0;
//     lng2 = lng2 * PI / 180.0;
//     double x = R * cos(lat1) * cos(lng1) - R * cos(lat2) * cos(lng2);
//     double y = R * cos(lat1) * sin(lng1) - R * cos(lat2) * sin(lng2);
//     double z = R * sin(lat1) - R * sin(lat2);
   
//     double ab = sqrt(x * x + y * y + z * z);
//     double tm = 2.0 * asin(ab / (2.0 * R));
//     double ans = tm * R;
   
//     return ans;
// }
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--) {
        double a, b, c, d;
        // cin >> a >> b >> c >> d;
        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        double ans1 = solve1(a, b, c, d);
        double ans2 = solve1(a, b, a, d) + solve1(a, d, c, d);
        // printf("%.7f::%.7f\n", solve1(a, b, a, d), solve1(a, d, c, d));
        printf("%.10f %.10f\n",ans1, ans2);
    }
    return 0;
}
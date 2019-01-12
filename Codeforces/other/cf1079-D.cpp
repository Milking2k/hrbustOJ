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
const double EPS = 1e-6;
int T,n,m;
double a,b,c;
struct node
{
    double x, y,len;
} A, B;
double dist(node a, node b){
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double gety(double x){
    return -1 * (c + a * x) / b;
}

double getx(double y){
    return -1 * (c + b * y) / a;
}
int main()
{
    //ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> a >> b >> c;
    cin >> A.x >> A.y >> B.x >> B.y;
    double kdefault = -a / b;
    double ans1 = abs(A.x - B.x) + abs(A.y - B.y);
    if (A.x == B.x || A.y == B.y){
        printf("%.7f\n", ans1);
        return 0;
    }

    double k = (A.y - B.y) / (A.x - B.x);
    if(kdefault*k < 0){
        printf("%.7f\n", ans1);
        return 0;
    }

    node aryA[4], aryB[4];
    aryA[1].x = A.x;
    aryA[1].y = gety(A.x);
    aryA[1].len = abs(aryA[1].y - A.y);

    aryA[2].y = A.y;
    aryA[2].x = getx(A.y);
    aryA[2].len = abs(aryA[2].x - A.x);

    aryB[1].x = B.x;
    aryB[1].y = gety(B.x);
    aryB[1].len = abs(aryB[1].y - B.y);

    aryB[2].y = B.y;
    aryB[2].x = getx(B.y);
    aryB[2].len = abs(aryB[2].x - B.x);

    double ans = 1e18;
    rep(i,1,2+1) rep(j,1,2+1){
        ans = min(ans, aryA[i].len + aryB[j].len + dist(aryA[i], aryB[j]));
    }
    ans = min(ans, ans1);
    printf("%.7f\n", ans);

    return 0;
}
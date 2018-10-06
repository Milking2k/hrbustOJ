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
#define Mod(a,b) a<b?a:a%b+b
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const ll mod = 1e9+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
const int N = 100010;
const double EPS = 1e-8;
int n,m,k;
PDD a[N], b[N];
double dis2(PDD a, PDD b){
    return sqrt(1.0*(a.fi-b.fi)*(a.fi-b.fi) + 1.0*(a.se-b.se)*(a.se-b.se));
}
PDD dir(PDD a, PDD b){
    return mp((b.fi - a.fi) / sqrt(dis2(a, b)), (b.se - a.se) / sqrt(dis2(a, b)));
}
PDD getn(PDD n1, PDD n2, double l)
{
    PDD n3;
    double len = dis2(n1, n2);
    double ex1 = (n2.fi - n1.fi) / len, ey1 = (n2.se - n1.se) / len;
    n3.fi = n1.fi + ex1 * l;
    n3.se = n1.se + ey1 * l;
    return n3;
}
double solve(PDD a, PDD b, PDD c, PDD d, PDD e1, PDD e2)
{ // a->b c->d
    // printf("%.2f %.2f (%.2f %.2f) -> %.2f %.2f (%.2f %.2f)\n", b.fi, b.se, e1.fi, e1.se, d.fi, d.se, e2.fi, e2.se);
    double res = 0;
    double A = (dis2(e1, e2));
    double B = 2.0 * (a.fi - c.fi) * (e1.fi - e2.fi) + 2.0 * (a.se - c.se) * (e1.se - e2.se);
    // printf("debug::%.6f %.6f %.6f %.6f \n", (a.fi - c.fi),(e1.fi - e2.fi) , (a.se - c.se),(e1.se - e2.se));
    double C = dis2(a, c);
    double x1 = (b.fi - a.fi) / e1.fi;
    x1 = min(x1, (b.se - a.se) / e1.se);
    x1 = min(x1, (d.fi - c.fi) / e2.fi);
    x1 = min(x1, (d.se - c.se) / e2.se);
    // printf("ABC::%.6f %.6f %.6f %.6f ", A, B, C,x1);
    if(B+EPS>0){
        res = C;
    }
    else{
        double delta = 4 * A * C - B * B;
        delta = min(delta, x1);
        res = delta/(4.0*A*C);
    }
    // printf("res:%.6f\n", res);
    return sqrt(res);
}
double solve(PDD n1, PDD n2, PDD n3, PDD n4)
{
    double L1 = dis2(n1, n2), L2 = dis2(n3, n4);
    double ex1 = (n2.fi - n1.fi) / L1, ey1 = (n2.se - n1.se) / L1;
    double ex2 = (n4.fi - n3.fi) / L2, ey2 = (n4.se - n3.se) / L2;
    double A = (ex1 - ex2) * (ex1 - ex2) + (ey1 - ey2) * (ey1 - ey2);
    double B = 2.0 * ((n1.fi - n3.fi) * (ex1 - ex2) + (n1.se - n3.se) * (ey1 - ey2));
    double C = (n1.fi - n3.fi) * (n1.fi - n3.fi) + (n1.se - n3.se) * (n1.se - n3.se);
    if (A == 0)
        return min(dis2(n1, n3), dis2(n2, n4));
    double t = -B / (2.0 * A);
    if (t < 0 || t > L1)
        return min(dis2(n1, n3), dis2(n2, n4));
    return sqrt(A * t * t + B * t + C);
}

int main()
{
    scanf("%d", &n);
    rep(i, 1, n + 1)
    {
        scanf("%lf%lf", &a[i].fi, &a[i].se);
    }

    scanf("%d", &m);
    rep(i, 1, n + 1)
    {
        scanf("%lf%lf", &b[i].fi, &b[i].se);
    }
    int len = min(n, m);
    PDD f1 = a[1], t1 = a[2], f2 = b[1], t2 = b[2];
    PDD cnt = f1;
    double ans = 0x3f3f3f3f;
    int i = 1, j = 1;
    while (i <= n && j <= m)
    {
        double l = dis2(f1, t1), r = dis2(f2, t2);
        PDD e1 = dir(f1, t1);
        PDD e2 = dir(f2, t2);
        if (l == r)
        {
            ans = min(ans, solve(f1, t1, f2, t2));
            f1 = t1;
            t1 = a[++i];
            f2 = t2;
            t2 = b[++j];
        }
        else if (l > r)
        {
            cnt = getn(f1, t1, dis2(f2, t2));
            ans = min(ans, solve(f1, cnt, f2, t2));
            f1 = cnt;
            f2 = b[++j];
            t2 = b[j];
        }
        else
        {
            cnt = getn(f2, t2, dis2(f1, t1));
            // printf("%.2f %.2f\n", cnt.fi, cnt.se);
            // puts("no.2");
            ans = min(ans, solve(f1, t1, f2, cnt));
            f1 = a[++i];
            t1 = a[i];
            f2 = cnt;
        }
    }
        printf("%.7f\n", ans);

    return 0;
}
 

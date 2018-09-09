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
const ll mod = 1e18+7;
inline int read(int &n){char c=getchar();int x=0,f=1;while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}return n = x*f;}
inline void read(int &a,int &b){read(a),read(b);}
inline void read(int &a,int &b,int &c){read(a,b),read(c);};
ll powmod(ll a,ll b) {ll res = 1; a%=mod; assert(b>=0); for(;b; b>>=1){if(b&1)res = res*a%mod; a = a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head


//---------------------------

// 结构定义与宏定义
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point
{
    double x,y;
};
struct line
{
    point a,b;
};
// 计算  s cross  t product  (P1-P0)x(P2-P0)
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double xmult(double x1,double y1,double x2,double y2,double x0,double y0)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
// 计算  t dot  t product  (P1-P0).(P2-P0)
double dmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
double dmult(double x1,double y1,double x2,double y2,double x0,double y0)
{
    return (x1-x0)*(x2-x0)+(y1-y0)*(y2-y0);
}
// 两点距离
double distance(point p1,point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

//---------------------------



const int N = 1e6+7;
double stx, sty, edx, edy;
struct circle
{
    double x, y, r;
} blu, rd;
ll ans = 0;
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while (cin >> stx >> sty){
        cin >> edx >> edy;
        cin >> blu.x >> blu.y >> blu.r;
        cin >> rd.x >> rd.y >> rd.r;

        double p2plen = distance(stx, sty, edx, edy);
        double st2cir = distance(stx, sty, rd.x, rd.y);
        double ed2cir = distance(edx, edy, rd.x, rd.y);
        double A1 = acos(rd.r / st2cir);
        double A2 = acos(rd.r / ed2cir);
        double A3 = acos((st2cir * st2cir + ed2cir * ed2cir - p2plen * p2plen) / (2 * st2cir * ed2cir));
        double A4 = A3 - A2 - A1;
        double f = sqrt(st2cir * st2cir - rd.r * rd.r);
        double d = sqrt(ed2cir * ed2cir - rd.r * rd.r);
        double b = A4 * rd.r;
        double ans = f + b + d;

        printf("%.2f\n",ans);
    }
    return 0;
}

/*
1152921504606846976

10000000000000000
18014398509481984

72057594037927936
144115188075855872
288230376151711744

215443.46900318837217592935665194
*/
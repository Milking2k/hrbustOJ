//china no.1
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <cstring>
#include <queue>
#include <list>
#include <stdio.h>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <functional>
#include <stdlib.h>
#include <time.h>
#include <bitset>
using namespace std;

#define pi acos(-1)
#define endl '\n'
#define srand() srand(time(0));
#define me(x,y) memset(x,y,sizeof(x));
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define close() ios::sync_with_stdio(0); cin.tie(0);
#define FOR(x,n,i) for(int i=x;i<=n;i++)
#define FOr(x,n,i) for(int i=x;i<n;i++)
#define W while
#define sgn(x) ((x) < 0 ? -1 : (x) > 0)
#define bug printf("***********\n");
#define db double
typedef long long LL;
const int INF=0x3f3f3f3f;
const LL LINF=0x3f3f3f3f3f3f3f3fLL;
const int dx[]={-1,0,1,0,1,-1,-1,1};
const int dy[]={0,1,0,-1,-1,1,-1,1};
const int maxn=2e2+10;
const int maxx=1e6+100;
const double EPS=1e-10;
const double eps=1e-10;
const int mod=10000007;
template<class T>inline T min(T a,T b,T c) { return min(min(a,b),c);}
template<class T>inline T max(T a,T b,T c) { return max(max(a,b),c);}
template<class T>inline T min(T a,T b,T c,T d) { return min(min(a,b),min(c,d));}
template<class T>inline T max(T a,T b,T c,T d) { return max(max(a,b),max(c,d));}
template <class T>
inline bool scan_d(T &ret){char c;int sgn;if (c = getchar(), c == EOF){return 0;}
while (c != '-' && (c < '0' || c > '9')){c = getchar();}sgn = (c == '-') ? -1 : 1;ret = (c == '-') ? 0 : (c - '0');
while (c = getchar(), c >= '0' && c <= '9'){ret = ret * 10 + (c - '0');}ret *= sgn;return 1;}

inline bool scan_lf(double &num){char in;double Dec=0.1;bool IsN=false,IsD=false;in=getchar();if(in==EOF) return false;
while(in!='-'&&in!='.'&&(in<'0'||in>'9'))in=getchar();if(in=='-'){IsN=true;num=0;}else if(in=='.'){IsD=true;num=0;}
else num=in-'0';if(!IsD){while(in=getchar(),in>='0'&&in<='9'){num*=10;num+=in-'0';}}
if(in!='.'){if(IsN) num=-num;return true;}else{while(in=getchar(),in>='0'&&in<='9'){num+=Dec*(in-'0');Dec*=0.1;}}
if(IsN) num=-num;return true;}

void Out(LL a){if(a < 0) { putchar('-'); a = -a; }if(a >= 10) Out(a / 10);putchar(a % 10 + '0');}
void print(LL a){ Out(a),puts("");}
//freopen( "in.txt" , "r" , stdin );
//freopen( "data.txt" , "w" , stdout );
//cerr << "run time is " << clock() << endl;

const double PI = acos(-1);
int dcmp(double x)
{
    if(fabs(x) < EPS) return 0;
    else return x < 0 ? -1 : 1;
}

struct Point
{
    double x, y;
    int id;
    //Point(const Point& rhs): x(rhs.x), y(rhs.y) { } //¿½±´¹¹Ôìº¯Êý
    Point(double x = 0, double y = 0) : x(x), y(y) { }
    inline void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    inline void print()
    {
        printf("%.6lf %.6lf\n",x,y);
    }
    bool operator == (const Point& e) const
    {
        return dcmp(x - e.x) == 0 && dcmp(y - e.y) == 0;
    }
    Point operator + (Point q){ return Point(x+q.x,y+q.y);}
    Point operator - (Point q){ return Point(x-q.x,y-q.y);}
    Point operator * (double q){ return Point(x*q,y*q);}
    Point operator / (double q){ return Point(x/q,y/q);}
    Point &operator +=(Point q){ x+=q.x;y+=q.y; return *this;}
    Point &operator -=(Point q){ x-=q.x;y-=q.y; return *this;}
    double operator *(const Point& q) const{
        return x*q.x+y*q.y;
    }
    double operator ^(const Point& q) const{
        return x*q.y-y*q.x;
    }
    double len2()
    {
        return x*x+y*y;
    }
    double len()
    {
        return sqrt(x*x+y*y);
    }

}Q[2010];

bool operator < (Point a, Point b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

bool cmp(Point p1,Point p2)//位置排序，找到最下方的；
{
    if(p1.y!=p2.y)
        return p1.y<p2.y;
    return p1.x<p2.x;//若有多个下方的找左边的；
}

//极角排序
Point polor;

bool polor_cmp(Point a,Point b)
{
    double tmp=(a-polor)^(b-polor);
    if(dcmp(tmp)==0)
        return (a-polor).len()<(b-polor).len();
    else if(dcmp(tmp)<0) return false;
    else return true;
}


typedef Point Vector;

//向量点积
double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }

//向量长度
double Length(Vector A) { return sqrt(Dot(A, A)); }

//向量夹角
//求两向量的夹角，cos（a,b） =（ 向量a * 向量b ） / （| a | * | b |） =  x1*x2 + y1*y2 / （| a | * | b |）
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }

//向量叉积  |a||b|sin<a,b>
//叉积的结果也是一个向量，是垂直于向量a，b所形成的平面，如果看成三维坐标的话是在 z 轴上，上面结果是它的模。
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }

//三角形有向面积的二倍
double Area2(Point A, Point B, Point C) { return Cross(B-A, C-A); }

//向量逆时针旋转rad度(弧度)
Vector Rotate(Vector A, double rad) //pi/2 90°
{
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

//计算向量A的单位法向量。左转90°，把长度归一。调用前确保A不是零向量。
Vector Normal(Vector A)
{
    double L = Length(A);
    return Vector(-A.y/L, A.x/L);
}
//共线或平行
bool Converxline(Vector A,Vector B,Vector C,Vector D)
{
    if((Area2(A,B,C)==0&&Area2(A,B,D)==0)
    ||Area2(A,B,C)*Area2(A,B,D)>0||Area2(C,D,A)*Area2(C,D,B)>0)
        return false;
    else
        return true;
}
//半平面交
bool on(Point a,Point b,Point p)
{
    return fabs((a-b)^(p-b))<eps;
}


/****************************************************************************
* 用直线上的一点p0和方向向量v表示一条指向。直线上的所有点P满足P = P0+t*v;
* 如果知道直线上的两个点则方向向量为B-A, 所以参数方程为A+(B-A)*t;
* 当t 无限制时， 该参数方程表示直线。
* 当t > 0时， 该参数方程表示射线。
* 当 0 < t < 1时， 该参数方程表示线段。
*****************************************************************************/

//直线交点,须确保两直线 P+tv 和 Q+tw 有唯一交点。当且仅当Cross(v,w)非0
Point getLineCircleIntersecion(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}
/*
Vector getLineCircleIntersecion(int x,int y)
{
    Vector p1 = A[x], p2 = B[x], q1 = A[y], q2 = B[y];
    return p1+(p2-p1)*(((q2-q1)^(q1-p1))/((q2-q1)^(p2-p1)));
}
*/
//点和直线的关系
int relation (Point p, Line l)
{
    //1:在左侧 2:在右侧 3:在直线上
    int c = dcmp (Cross (p-l.P,l.v));
    if (c < 0) return 1;
    else if (c > 0) return 2;
    else return 3;
}

//判断点在射线上
bool point_on_halfline (Point p, Line l)
{
    int id = relation (p, l);
    if (id != 3) return 0;
    return dcmp (Dot (p-l.P,l.v)) >= 0;
}

//点到直线距离
double DistanceToLine(Point P, Point A, Point B)
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2) / Length(v1)); //不取绝对值，得到的是有向距离
}
//点到线段的距离
double DistanceToSegmentS(Point P, Point A, Point B)
{
    if(A == B) return Length(P-A);
    Vector v1 = B-A, v2 = P-A, v3 = P-B;
    if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}
//点在直线上的投影
Point GetLineProjection(Point P, Point A, Point B)
{
    Vector v = B - A;
    return A+v*(Dot(v, P-A)/Dot(v, v));
}

//点在直线上的投影
Point GetLineProjection(Point p,Line l)
{
    Vector v = l.v;
    return l.P+v*(Dot(v, p-l.P)/Dot(v, v));
}
//点在直线的对称点
Point symmetrypoint(Point p,Line l)
{
    Point q=GetLineProjection(p,l);
    return Point(2*q.x-p.x,2*q.y-p.y);
}

//线段相交判定，交点不在一条线段的端点
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1);
    double c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}

//判断点是否在点段上，不包含端点
bool OnSegment(Point P, Point a1, Point a2)
{
    return dcmp(Cross(a1-P, a2-P) == 0 && dcmp((Dot(a1-P, a2-P)) < 0));
}

//计算凸多边形面积
double ConvexPolygonArea(Point *p, int n)
{
    double area = 0;
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i] - p[0], p[i+1] - p[0]);
    return area/2;
}

//计算多边形的有向面积
double PolygonArea(Point *p, int n)
{
    double area = 0;
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i] - p[0], p[i+1] - p[0]);
    return area/2;
}

/***********************************************************************
* Morley定理：三角形每个内角的三等分线，相交成的三角形是等边三角形。
* 欧拉定理：设平面图的定点数，边数和面数分别为V,E,F。则V+F-E = 2;
************************************************************************/
//Morley定理
Point getD(Point A, Point B, Point C)
{
    Vector v1=C-B;
    double a1=Angle(A-B,v1);
    v1=Rotate(v1,a1/3);
    Vector v2=B-C;
    double a2=Angle(A-C,v2);
    v2=Rotate(v2,-a2/3);
    return getLineCircleIntersecion(B,v1,C,v2);
}

//欧拉定理
/*void oula(int n)
{
    n--;
    int c=n,e=n;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
        {
            if(SegmentProperIntersection(P[i],[i+1],P[j],P[j+1]))
            {
                V[c++]=getLineCircleIntersecion(P[i],P[i+1]-P[i],P[j],P[j+1]-P[j]);
            }
        }
    sort(V,V+c);
    c=unique(V,V+c)-V;
    for(int i=0;i<c;i++)
        for(int j=0;j<n;j++)
    {
        if(OnSegment(V[i],P[j],p[j+1])) e++;
    }
    //cout<<e+2-c<<endl;
}

//定义圆
struct Circle
{
    Point c;
    double r;
    Circle() {}
    Circle(const Circle& rhs): c(rhs.c), r(rhs.r) { }
    Circle(const Point& c, const double& r): c(c), r(r) { }

    inline void input()
    {
        scanf("%lf%lf%lf",&c.x,&c.y,&r);
    }
    inline void print()
    {
        printf("%.6lf %.6lf\n",c.x,c.y);
    }
    Point point(double ang) const { return Point(c.x + cos(ang)*r, c.y + sin(ang)*r); } //圆心角所对应的点
    double area(void) const { return PI * r * r; }
};*/
struct Circle
{
    Point c;
    double r;

    Circle(){}
    Circle(Point c, double r):c(c), r(r){}

    int input()
    {
        return scanf("%lf%lf%lf", &c.x, &c.y, &r);
    }

    Point point(double a)
    {
        return Point(c.x + r * cos(a), c.y + r * sin(a));
    }
};
/*
struct Line
{
    Point P;    //直线上一点
    Vector v; //方向向量(半平面交中该向量左侧表示相应的半平面)
    double ang; //极角，即从x正半轴旋转到向量v所需要的角（弧度）
    Line() { }  //构造函数
    Line(const Line& L): P(L.P), v(L.v), ang(L.ang) { }
    Line(const Point& P, const Vector& v): P(P), v(v) { ang = atan2(v.y, v.x); }

    bool operator < (const Line& L) const//极角排序
    {
        return ang < L.ang;
    }
    Point point(double t) { return P + v*t; }
};*/
struct Line{
    Point P;
    Point v;

    Line(){}
    Line(Point P, Point v):P(P), v(v){}
    bool operator==(Line z)///
    {
        return (P==z.P)&&(v==z.v);
    }
    //ax+by+c=0
    Line(double _a,double _b,double _c)///
    {
        if (dcmp(_a)==0)
        {
            a=Point(0,-_c/_b);
            b=Point(1,-_c/_b);
        }
        else if (dcmp(_b)==0)
        {
            a=Point(-_c/_a,0);
            b=Point(-_c/_a,1);
        }
        else
        {
            a=Point(0,-_c/_b);
            b=Point(1,(-_c-_a)/_b);
        }
    }
    int read(){
        return scanf("%lf%lf%lf%lf", &P.x, &P.y, &v.x, &v.y);
    }
    void adjust()
    {
        if (v<P)swap(P,v);
    }
    double angle()//直线倾斜角 0<=angle<180
    {
        double k=atan2(v.y-P.y,v.x-P.x);///
        if (dcmp(k)<0)k+=pi;
        if (dcmp(k-pi)==0)k-=pi;
        return k;
    }
    Point point(double t){
        return P + v * t;
    }
};
//直线和圆的交点，返回交点个数，结果存在sol中。
//该代码没有清空sol。
//(at+b)^2+(ct+d)^2=r^2; et^2+ft+g=0;
int getLineCircleIntersecion(Line l, Circle C, double& t1, double& t2, vector<Point>& sol)
{
    double a = l.v.x;
    double b = l.P.x - C.c.x;
    double c = l.v.y;
    double d = l.P.y - C.c.y;
    double e = a * a + c * c;
    double f = 2 * (a * b + c * d);
    double g = b * b + d * d - C.r * C.r;
    double delta = f * f - 4 * e * g;
    double dist = DistanceToLine(C.c, l.P, l.P+l.v);
    if(dcmp(dist - C.r) == 0)
    {      //相切，此处需特殊判断，不能用delta
        t1 = t2 = -f / (2 * e);
        sol.push_back(l.point(t1));
        return 1;
    }
    if(dcmp(delta) < 0) return 0;       //相离
    else
    {       //相交
        t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(l.point(t1));
        t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(l.point(t2));
        return 2;
    }
}

//计算向量极角
double angle(Vector v){return atan2(v.y,v.x);}

//两圆相交
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol)
{
    double d = Length(C1.c - C2.c);
    if(dcmp(d) == 0)
    {
        if(dcmp(C1.r - C2.r == 0)) return -1;    //两圆完全重合
        return 0;                                //同心圆，半径不一样
    }
    if(dcmp(C1.r + C2.r - d) < 0) return 0;//外离
    if(dcmp(fabs(C1.r - C2.r)- d) > 0) return 0;//内含

    double a = angle(C2.c - C1.c);               //向量C1C2的极角
    double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
    //C1C2到C1P1的角
    Point p1 = C1.point(a-da), p2 = C1.point(a+da);
    sol.push_back(p1);
    if(p1 == p2) return 1;//外切
    sol.push_back(p2);
    return 2;
}
//圆和多边形相交面积
//for(int i=1;i<=n;i++)
//    ans += TriAngleCircleInsection(C, Q[i], Q[i+1]);

double TriAngleCircleInsection(Circle C, Point A, Point B)
{
    Vector OA = A-C.c, OB = B-C.c;
    Vector BA = A-B, BC = C.c-B;
    Vector AB = B-A, AC = C.c-A;
    double DOA = Length(OA), DOB = Length(OB),DAB = Length(AB), r = C.r;
    if(dcmp(Cross(OA,OB)) == 0) return 0;
    if(dcmp(DOA-C.r) < 0 && dcmp(DOB-C.r) < 0) return Cross(OA,OB)*0.5;
    else if(DOB < r && DOA >= r)
    {
        double x = (Dot(BA,BC) + sqrt(r*r*DAB*DAB-Cross(BA,BC)*Cross(BA,BC)))/DAB;
        double TS = Cross(OA,OB)*0.5;
        return asin(TS*(1-x/DAB)*2/r/DOA)*r*r*0.5+TS*x/DAB;
    }
    else if(DOB >= r && DOA < r)
    {
        double y = (Dot(AB,AC)+sqrt(r*r*DAB*DAB-Cross(AB,AC)*Cross(AB,AC)))/DAB;
        double TS = Cross(OA,OB)*0.5;
        return asin(TS*(1-y/DAB)*2/r/DOB)*r*r*0.5+TS*y/DAB;
    }
    else if(fabs(Cross(OA,OB)) >= r*DAB || Dot(AB,AC) <= 0 || Dot(BA,BC) <= 0)
    {
        if(Dot(OA,OB) < 0)
        {
            if(Cross(OA,OB) < 0) return (-acos(-1.0)-asin(Cross(OA,OB)/DOA/DOB))*r*r*0.5;
            else                 return ( acos(-1.0)-asin(Cross(OA,OB)/DOA/DOB))*r*r*0.5;
        }
        else                     return asin(Cross(OA,OB)/DOA/DOB)*r*r*0.5;
    }
    else
    {
        double x = (Dot(BA,BC)+sqrt(r*r*DAB*DAB-Cross(BA,BC)*Cross(BA,BC)))/DAB;
        double y = (Dot(AB,AC)+sqrt(r*r*DAB*DAB-Cross(AB,AC)*Cross(AB,AC)))/DAB;
        double TS = Cross(OA,OB)*0.5;
        return (asin(TS*(1-x/DAB)*2/r/DOA)+asin(TS*(1-y/DAB)*2/r/DOB))*r*r*0.5 + TS*((x+y)/DAB-1);
    }
}

//过定点做圆的切线
//过点p做圆C的切线，返回切线个数。v[i]表示第i条切线
int getTangents(Point p, Circle C, Vector* v)
{
    Vector u = C.c - p;
    double dist = Length(u);
    if(dist < C.r) return 0;
    else if(dcmp(dist - C.r) == 0)
    {
        v[0] = Rotate(u, PI/2);
        return 1;
    }
    else
    {
        double ang = asin(C.r / dist);
        v[0] = Rotate(u, -ang);
        v[1] = Rotate(u, +ang);
        return 2;
    }
}
/*
//两圆位置关系判定
int GetCircleLocationRelation(const Circle& A, const Circle& B)
{
    double d = Length(A.c-B.c);
    double sum = A.r + B.r;
    double sub = fabs(A.r - B.r);
    if (dcmp(d) == 0) return dcmp(sub) != 0;
    if (dcmp(d - sum) > 0) return XiangLi;
    if (dcmp(d - sum) == 0) return WaiQie;
    if (dcmp(d - sub) > 0 && dcmp(d - sum) < 0) return INTERSECTING;
    if (dcmp(d - sub) == 0) return NeiQie;
    if (dcmp(d - sub) < 0) return NeiHan;
}

//两圆相交的面积
double GetCircleIntersectionArea(const Circle& A, const Circle& B)
{
    int rel = GetCircleLocationRelation(A, B);
    if (rel < INTERSECTING) return min(A.area(), B.area());
    if (rel > INTERSECTING) return 0;
    double dis = Length(A.c - B.c);
    double ang1 = acos((A.r*A.r + dis*dis - B.r*B.r) / (2.0*A.r*dis));
    double ang2 = acos((B.r*B.r + dis*dis - A.r*A.r) / (2.0*B.r*dis));
    return ang1*A.r*A.r + ang2*B.r*B.r - A.r*dis*sin(ang1);
}
*/
//三角形外接圆
Circle CircumscribedCircle(Point p1,Point p2,Point p3)
{
    double Bx=p2.x-p1.x,By=p2.y-p1.y;
    double Cx=p3.x-p1.x,Cy=p3.y-p1.y;
    double D=2*(Bx*Cy-By*Cx);
    double cx=(Cy*(Bx*Bx+By*By)-By*(Cx*Cx+Cy*Cy))/D+p1.x;
    double cy=(Bx*(Cx*Cx+Cy*Cy)-Cx*(Bx*Bx+By*By))/D+p1.y;
    Point p=Point(cx,cy);//圆心
    return Circle(p,Length(p1-p));//半径
}
//三角形内接圆
Circle InscribedCircle(Point p1,Point p2,Point p3)
{
    double a=Length(p3-p2);
    double b=Length(p3-p1);
    double c=Length(p2-p1);
    Point p=(p1*a+p2*b+p3*c)/(a+b+c);
    return Circle(p,DistanceToLine(p,p2,p3));
}

//设圆的方程为(x-a)²+(y-b)²=R²
//圆上有一点(x0,y0)
//则过这个点的切线为 (x-a)(x0-a)+(y-b)(y0-b)=R²
//求点到圆的直线
int TangentLineThroughPoint(Point p, Circle C, Vector *v)
{
    Vector u = C.c - p;
    double dist = Length(u);
    if(dcmp(dist - C.r) < 0) return 0;//点在圆内
    else if(dcmp(dist - C.r) < eps)
    {
        v[0] = Rotate(u, pi / 2);
        return 1;//点在圆上
    }
    else
    {
        double ang = asin(C.r / dist);//极角
        v[0] = Rotate(u, ang);
        v[1] = Rotate(u, -ang);
        return 2;//点在圆外
    }
}
void ThroughPoint(Vector *v,int cnt)
{
    double ret[3];
    for(int i=0;i<cnt;i++)
    {
        ret[i]=angle(v[i]);
        if(dcmp(ret[i] - pi) == 0) ret[i] = 0;
            if(dcmp(ret[i]) < 0) ret[i] += pi;
    }
    sort(ret, ret + cnt);
    printf("[");
    for(int i = 0; i < cnt; i++)
    {
        printf("%.6f", ret[i] / pi * 180);
        if(cnt == 2 && !i) printf(",");
    }
    puts("]");
}

//求经过p1并且与一条直线相切的一组圆
void CircleThroughAPointAndTangentToALineWithRadius(Point p, Point p1, Point p2, double r)
{
    Vector AB = p2 - p1;
    Vector change1 = Rotate(AB, pi / 2) / Length(AB) * r;
    Vector change2 = Rotate(AB, -pi / 2) / Length(AB) * r;
    Line l1(p1 + change1, AB);
    Line l2(p1 + change2, AB);
    vector<Point> sol;
    sol.clear();
    double t1, t2;
    int cnt1 = getLineCircleIntersecion(l1, Circle(p, r), t1, t2, sol);
    int cnt2 = getLineCircleIntersecion(l2, Circle(p, r), t1, t2, sol);
    int cnt = cnt1 + cnt2;
    if(cnt) sort(sol.begin(), sol.end());
    printf("[");
    for(int i = 0; i < cnt; i++)
    {
        printf("(%.6f,%.6f)", sol[i].x, sol[i].y);
        if(cnt == 2 && !i) printf(",");
    }
    puts("]");
}

//给定两个向量，求两向量方向内夹着的圆的圆心。圆与两线均相切，圆的半径已给定
//求圆
void CircleTangentToTwoLinesWithRadius(Point A, Point B, Point C, Point D, double r)
{
    Vector AB = B - A;
    Vector change = Normal(AB) * r;
    Point newA1 = A + change;
    Point newA2 = A - change;
    Vector CD = D - C;
    Vector update = Normal(CD) * r;
    Point newC1 = C + update;
    Point newC2 = C - update;
    Point p[5];
    p[0] = getLineCircleIntersecion(newA1, AB, newC1, CD);
    p[1] = getLineCircleIntersecion(newA1, AB, newC2, CD);
    p[2] = getLineCircleIntersecion(newA2, AB, newC1, CD);
    p[3] = getLineCircleIntersecion(newA2, AB, newC2, CD);
    sort(p, p + 4);
    printf("[");
    printf("(%.6f,%.6f)", p[0].x, p[0].y);
    for(int i = 1; i < 4; i++)
    {
        printf(",(%.6f,%.6f)", p[i].x, p[i].y);
    }
    puts("]");
}

//给定两相离圆，求与这个两圆同时外切的圆
void CircleTangentToTwoDisjointCirclesWithRadius(Circle C1, Circle C2, double r){
    Vector CC = C2.c - C1.c;
    double rdist = Length(CC);
    if(dcmp(2 * r - rdist + C1.r + C2.r) < 0) puts("[]");
    else if(dcmp(2 * r - rdist + C1.r + C2.r) == 0)
    {
        double ang = angle(CC);
        Point A = C1.point(ang);
        Point B = C2.point(ang + pi);
        Point ret = (A + B) / 2;
        printf("[(%.6f,%.6f)]\n", ret.x, ret.y);
    }
    else
    {
        Circle A = Circle(C1.c, C1.r + r);
        Circle B = Circle(C2.c, C2.r + r);
        vector<Point> sol;
        sol.clear();
        getCircleCircleIntersection(A, B, sol);
        sort(sol.begin(), sol.end());
        printf("[(%.6f,%.6f),(%.6f,%.6f)]\n", sol[0].x, sol[0].y, sol[1].x, sol[1].y);
    }
}

//三边构成三角形的判定
bool check_length(double a, double b, double c)
{
    return dcmp(a+b-c) > 0 && dcmp(fabs(a-b)-c) < 0;
}
bool isTriangle(double a, double b, double c)
{
    return check_length(a, b, c) && check_length(a, c, b) && check_length(b, c, a);
}


//点在三角形内部
int cross(const Point &a, const Point &b, const Point &p)
{
    return (b.x - a.x)*(p.y - a.y) - (b.y - a.y)*(p.x - a.x);
}

bool toLeft(const Point &a, const Point &b, const Point &p)
{
    return cross(a, b, p) > 0;
}

bool inTriangle(const Point &p, const Point &a, const Point &b, const Point &c)
{
    bool res = toLeft(a, b, p);
    if (res != toLeft(b, c, p))
        return false;
    if (res != toLeft(c, a, p))
        return false;
    if (cross(a, b, c) == 0)    //ABC is in one line
        return false;
    return true;
}
/*
typedef vector<Point> Polygon;

//平行四边形的判定（保证四边形顶点按顺序给出）
bool isParallelogram(Polygon p)
{
    if (dcmp(Length(p[0]-p[1]) - Length(p[2]-p[3])) || dcmp(Length(p[0]-p[3]) - Length(p[2]-p[1]))) return false;
    Line a = Line(p[0], p[1]-p[0]);
    Line b = Line(p[1], p[2]-p[1]);
    Line c = Line(p[3], p[2]-p[3]);
    Line d = Line(p[0], p[3]-p[0]);
    return dcmp(a.ang - c.ang) == 0 && dcmp(b.ang - d.ang) == 0;
}

//梯形的判定
bool isTrapezium(Polygon p)
{
    Line a = Line(p[0], p[1]-p[0]);
    Line b = Line(p[1], p[2]-p[1]);
    Line c = Line(p[3], p[2]-p[3]);
    Line d = Line(p[0], p[3]-p[0]);
    return (dcmp(a.ang - c.ang) == 0 && dcmp(b.ang - d.ang)) || (dcmp(a.ang - c.ang) && dcmp(b.ang - d.ang) == 0);
}

//菱形的判定
bool isRhombus(Polygon p)
{
    if (!isParallelogram(p)) return false;
    return dcmp(Length(p[1]-p[0]) - Length(p[2]-p[1])) == 0;
}

//矩形的判定
bool isRectangle(Polygon p)
{
    if (!isParallelogram(p)) return false;
    return dcmp(Length(p[2]-p[0]) - Length(p[3]-p[1])) == 0;
}

//正方形的判定
bool isSquare(Polygon p)
{
    return isRectangle(p) && isRhombus(p);
}

//三点共线的判定
bool isCollinear(Point A, Point B, Point C)
{
    return dcmp(Cross(B-A, C-B)) == 0;
}

//点在多边形内的判定
int isPointInPolygon(Point p, Polygon poly)
{
    int wn = 0;
    int n = poly.size();
    for(int i = 0; i < n; i++)
    {
        if(OnSegment(p, poly[i], poly[(i+1)%n])) return -1; //在边界上
        int k = dcmp(Cross(poly[(i+1)%n]-poly[i], p-poly[i]));
        int d1 = dcmp(poly[i].y - p.y);
        int d2 = dcmp(poly[(i+1)%n].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) wn++;
        if(k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if(wn != 0) return 1;       //内部
    return 0;                   //外部
}

//凸包
凸包的点数位ch.size();
vector<Point> ConvexHull(vector<Point> p)
{
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());

    int n = p.size();
    int m = 0;
    vector<Point> ch(n+1);
    for(int i = 0; i < n; ++i)
    {
        while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; --i)
    {
        while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(m > 1) m--;
    ch.resize(m);
    return ch;
}

//点P在有向直线L左边的判定(线上不算)
bool OnLeft(const Line& L, const Point& P)
{
    return Cross(L.v, P-L.P) > 0;
}

//两直线交点，假定交点唯一存在
Point GetIntersection(Line a, Line b)
{
    Vector u = a.P - b.P;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.P+a.v*t;
}
*/
string s;
string s1="CircumscribedCircle",s2="InscribedCircle",
s3="TangentLineThroughPoint",s4="CircleThroughAPointAndTangentToALineWithRadius",
s5="CircleTangentToTwoLinesWithRadius";
int main()
{
    //freopen( "in.txt" , "r" , stdin );
    W(cin>>s&&s!="")
    {
        if(s==s1)
        {
            Point p1,p2,p3;
            p1.input();p2.input();p3.input();
            Circle ret=CircumscribedCircle(p1, p2, p3);
            printf("(%f,%f,%f)\n",ret.c.x,ret.c.y,ret.r);
        }
        else if(s==s2)
        {
            Point p1,p2,p3;
            p1.input();p2.input();p3.input();
            Circle ret=InscribedCircle(p1, p2, p3);
            printf("(%f,%f,%f)\n",ret.c.x,ret.c.y,ret.r);
        }
        else if(s==s3)
        {
            Circle C;
            Point p;
            C.input();
            p.input();
            Vector v[3];
            int cnt = TangentLineThroughPoint(p, C, v);
            ThroughPoint(v,cnt);
        }
        else if(s==s4)
        {
            Point p,p1,p2;
            double r;
            p.input();p1.input();p2.input();
            scanf("%lf",&r);
            CircleThroughAPointAndTangentToALineWithRadius(p, p1, p2, r);
        }
        else if(s==s5)
        {
            Point A,B,C,D;
            double r;
            A.input();B.input();C.input();D.input();
            scanf("%lf",&r);
            CircleTangentToTwoLinesWithRadius(A, B, C, D, r);
        }
        else
        {
            Circle c1,c2;
            double r;
            c1.input();c2.input();
            scanf("%lf",&r);
            CircleTangentToTwoDisjointCirclesWithRadius(c1, c2, r);
        }
    }
}

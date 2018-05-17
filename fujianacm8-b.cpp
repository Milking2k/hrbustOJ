#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct point
{
    double x,y;
    point() {}
    point(double _x,double _y)
    {
        x = _x;
        y = _y;
    }
    point operator -(const point &b)const
    {
        return point(x - b.x,y - b.y);
    }
    double operator ^(const point &b)const
    {
        return x*b.y - y*b.x;
    }
    double operator *(const point &b)const
    {
        return x*b.x + y*b.y;
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
};

struct Line
{
    point s,e;
    Line() {}
    Line(point _s,point _e)
    {
        s = _s;
        e = _e;
    }
};

bool inter(Line l1,Line l2)
{
    return
        max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
        max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
        max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
        max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
        sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
        sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}
bool OnSeg(point P,Line L)
{
    return
        sgn((L.s-P)^(L.e-P)) == 0 &&
        sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
        sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

int inPoly(point p,point poly[],int n)
{
//    printf("test %d %f %f\n",n,p.x,p.y);
    int cnt;
    Line ray,side;
    cnt = 0;
    ray.s = p;
    ray.e.y = p.y;
    ray.e.x = -100000000000.0;//-INF,注意取值防止越界
    for(int i = 0; i < n; i++)
    {
        side.s = poly[i];
        side.e = poly[(i+1)%n];
        if(OnSeg(p,side))return 0;
        if(sgn(side.s.y - side.e.y) == 0)
            continue;
        if(OnSeg(side.s,ray))
        {
            if(sgn(side.s.y - side.e.y) > 0)cnt++;
        }
        else if(OnSeg(side.e,ray))
        {
            if(sgn(side.e.y - side.s.y) > 0)cnt++;
        }
        else if(inter(ray,side))
            cnt++;
    }
    if(cnt % 2 == 1)return 1;
    else return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        point p[10];
        point pp[10];
        p[0].input();
        p[1].input();
        p[2].input();

        pp[0].input();
        pp[1].input();
        pp[2].input();

        Line line[10];
        Line line1[10];
        line[0]=Line(p[0],p[1]);
        line[1]=Line(p[1],p[2]);
        line[2]=Line(p[2],p[0]);

        line1[0]=Line(pp[0],pp[1]);
        line1[1]=Line(pp[1],pp[2]);
        line1[2]=Line(pp[2],pp[0]);

        int as=inPoly(pp[0],p,3);
        int qw=inPoly(pp[1],p,3);
        int zx=inPoly(pp[2],p,3);
        int as1=inPoly(p[0],pp,3);
        int qw1=inPoly(p[1],pp,3);
        int zx1=inPoly(p[2],pp,3);
        int ok=0;

//        printf("fuck %d\n",inter(line[1],line1[2]));

        if(inter(line[0],line1[0]))ok++;
        if(inter(line[0],line1[1]))ok++;
        if(inter(line[0],line1[2]))ok++;

        if(inter(line[1],line1[0]))ok++;
        if(inter(line[1],line1[1]))ok++;
        if(inter(line[1],line1[2]))ok++;

        if(inter(line[2],line1[0]))ok++;
        if(inter(line[2],line1[1]))ok++;
        if(inter(line[2],line1[2]))ok++;
//        printf("test %d %d %d %d %d %d %d\n",ok,qw,as,zx,qw1,as1,zx1);
        if(ok==0){
            if((qw==-1&&as==-1&&zx==-1)&&(qw1==-1&&as1==-1&&zx1==-1)){
                puts("disjoint");
            }
            else{
                puts("contain");
            }
        }
        else{
            puts("intersect");
        }
    }
    return 0;
}
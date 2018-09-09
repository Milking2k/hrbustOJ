#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;

const double eps = 1e-8;
int sgn(double x)
{
    if(fabs(x) < eps)return 0;
    if(x < 0)return -1;
    else return 1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y)
    {
        x = _x;y = _y;
    }
    Point operator -(const Point &b)const
    {
        return Point(x - b.x,y - b.y);
    }
    //叉积
    double operator ^(const Point &b)const
    {
        return x*b.y - y*b.x;
    }
    //点积
    double operator *(const Point &b)const
    {
        return x*b.x + y*b.y;
    }
};
struct Line
{
    Point s,e;
    Line(){}
    Line(Point _s,Point _e)
    {
        s = _s;e = _e;
    }
    //两直线相交求交点
    //第一个值为0表示直线重合，为1表示平行，为0表示相交,为2是相交
    //只有第一个值为2时，交点才有意义
    pair<int,Point> operator &(const Line &b)const
    {
        Point res = s;
        if(sgn((s-e)^(b.s-b.e)) == 0)
        {
            if(sgn((s-b.e)^(b.s-b.e)) == 0)
                return make_pair(0,res);//重合
            else return make_pair(1,res);//平行
        }
        double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
        res.x += (e.x-s.x)*t;
        res.y += (e.y-s.y)*t;
        return make_pair(2,res);
    }
};

//*判断线段相交
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

int main()
{
    int x1,y1,x2,y2,x3,y3,x4,y4;
    int T;
    Line l1,l2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        l1 = Line(Point(x1,y1),Point(x2,y2));
        l2 = Line(Point(x3,y3),Point(x4,y4));
        if(sgn(l1.s.y-l1.e.y)==0 || sgn(l2.s.y-l2.e.y) == 0)
        {
            printf("0.00\n");
            continue;
        }
        if(sgn(l1.s.y-l1.e.y) < 0)swap(l1.s,l1.e);
        if(sgn(l2.s.y-l2.e.y) < 0)swap(l2.s,l2.e);
        if(inter(l1,l2) == false)
        {
            printf("0.00\n");
            continue;
        }
        //口被封掉的情况
        if(inter(Line(l1.s,Point(l1.s.x,100000)),l2) )
        {
            printf("0.00\n");
            continue;
        }
        //口被封掉
        if(inter(Line(l2.s,Point(l2.s.x,100000)),l1) )
        {
            printf("0.00\n");
            continue;
        }
        pair<int,Point>pr;
        pr = l1 & l2;
        Point p = pr.second;
        double ans1;
        pr = l1 & Line(Point(100000,l2.s.y),l2.s);
        Point p1 = pr.second;
        ans1 = fabs( (l2.s-p)^(p1-p) )/2;
        double ans2;
        pr = l2 & Line(Point(100000,l1.s.y),l1.s);
        Point p2 = pr.second;
        ans2 = fabs( (l1.s-p)^(p2-p) )/2;
        printf("%.2lf\n",min(ans1,ans2));
    }
    return 0;
}
/*
            if(a.y>point.y){cnt = a;flag = 0;}
            else if(b.y>point.y){cnt = b;flag = 0;}
            if(c.y>point.y && cnt.y>c.y){cnt = c;flag = 1;}
            else if(d.y>point.y && cnt.y>d.y){cnt = c;flag = 1;}
            double sum;
            if(flag==0){
                sum = cnt.x + (c.x-b.x)*(-1*c.y)*1.0/(c.y-d.y)+c.x+ (c.x-d.x)*cnt.y*1.0/(c.y-d.y);
            }
            else{
                sum = cnt.x + (a.x-b.x)*(-1*a.y)*1.0/(a.y-b.y)+a.x+ (a.x-b.x)*cnt.y*1.0/(a.y-b.y);
            }

            printf("%.2lf\n",fabs(sum)*fabs(point.y-cnt.y)*1.0/2);
            */
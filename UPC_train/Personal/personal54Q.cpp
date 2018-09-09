#include <iostream>  
#include <cmath>

#define eps 1e-8  
#define oo 1e5  
using namespace std;  
const int maxn=105;  
  
struct point  
{  
       double x,y;  
       point() {}  
       point(double xx,double yy)   
       {  
                    x=xx;y=yy;  
       }  
}p[maxn];  
int n;  
  
int sig(double x)  
{  
    if (x<-eps) return -1;  
    if (x>eps) return 1;  
    return 0;  
}  
  
void get(const point& p1,const point& p2,double & a,double & b,double & c)  
{  
     a=p2.y-p1.y;  
     b=p1.x-p2.x;  
     c=p2.x*p1.y-p2.y*p1.x;  
}  
  
point intersect(point u,point v,double a,double b,double c)  
{  
      double d,e,f;  
      get(u,v,d,e,f);  
      point ret;  
      ret.x=(b*f-c*e)/(a*e-b*d);  
      ret.y=(a*f-c*d)/(b*d-a*e);  
      return ret;  
}  
  
void cut(int& n,point* p,double a,double b,double c)  
{  
      int m=0,i,t;  
      point pp[maxn];  
      for (i=0;i<n;i++)  
          if (sig(a*p[i].x+b*p[i].y+c)<=0)   
             pp[m++]=p[i];  
          else  
          {  
              t=(i-1+n)%n;  
              if (sig(a*p[t].x+b*p[t].y+c)<0) pp[m++]=intersect(p[t],p[i],a,b,c);  
              t=(i+1)%n;  
              if (sig(a*p[t].x+b*p[t].y+c)<0) pp[m++]=intersect(p[t],p[i],a,b,c);  
          }  
      for (i=0;i<m;i++)  
          p[i]=pp[i];  
      n=m;  
}  
  
bool ok(double mid)  
{  
     double a,b,c;  
     int nn=4,i;  
     point tp[maxn];  
     tp[0]=point(-oo,oo);  
     tp[1]=point(-oo,-oo);  
     tp[2]=point(oo,-oo);  
     tp[3]=point(oo,oo);  
     for (i=0;i<n;i++)  
     {  
         get(p[i],p[(i+1)%n],a,b,c);  
         c+=mid*sqrt(a*a+b*b);  
         cut(nn,tp,a,b,c);  
         if (nn==0) break;  
     }  
     return nn>0;  
}  
  
double work()  
{  
       double ll=0,rr=1e4,mid;  
       while (rr-ll>=1e-6)  
       {  
             mid=(ll+rr)/2;  
             if (ok(mid)) ll=mid;  
             else rr=mid;  
       }  
       return ll;  
}  
  
int main()  
{  
    // freopen("pin.txt","r",stdin);  
    // freopen("pou.txt","w",stdout);  
    int i;  
    while (1)  
    {  
          cin >> n;  
          if (n==0) break;  
          for (i=0;i<n;i++)  
              cin >> p[i].x >> p[i].y;  
          cout.setf(ios_base::fixed,ios_base::floatfield);  
          cout.precision(7);  
          cout << work() << endl;  
    }  
    return 0;  
}
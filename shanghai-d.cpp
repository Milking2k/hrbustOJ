#include <bits/stdc++.h>
using namespace std;
 
const double PI=acos(-1.0);
const double eps=1e-18;
double n,l;
double area(double a,double b,double c)
{
    double p=(a+b+c)/2.0;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
 
double solve(double x,double as)
{
    double len=x/(2.0*cos((PI-as)/2.0));
//    printf("zzzz %f\n",len);
    return area(x,len,len)*n;
}
int main()
{
    int T;
//    printf("%f\n",cos(PI/2.0));
    scanf("%d",&T);
    while(T--){
        double a;
        scanf("%lf%lf%lf",&n,&a,&l);
        double as=(PI*(n-2))/n;
        double qw=(2*PI)/n;
        double asd=solve(a,qw);
        int ans=0;
//        printf("test1 %f %f\n",asd,l);
        while(asd-eps>l){
            double zz=a*a+a*a-2*a*a*cos(as);
            a=sqrt(zz);
            a/=2.0;
//            printf("aaaaaa %f\n",a);
            asd=solve(a,qw);
            ans++;
//            printf("test %f\n",asd);
//            if(asd+eps<=l)break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
double angle(double AB, double AC, double BC)
{
    return acos((AC*AC+AB*AB-BC*BC)/(2*AB*AC));
}
int main()
{
    double ab, ac, ad, bc, bd, cd;
    double a, b, c, ga, gb, gc, gw;
    while(scanf("%lf%lf%lf%lf%lf%lf", &ab, &ac, &ad, &bc, &bd, &cd)!=EOF)
    {
        a=ad;b=ac;c=ab;
        ga=angle(ac, ad, cd);
        gb=angle(ac, ab, bc);
        gc=angle(ad, ab, bd);
        gw=(ga+gb+gc)/2;
        printf("%.4lf\n", sqrt(sin(gw)*sin(gw-ga)*sin(gw-gb)*sin(gw-gc))*a*b*c/3);
    }
    return 0;
}
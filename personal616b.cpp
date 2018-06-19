//#include <bits/stdc++.h>
#include <iostream>
#include<cstdio>
using namespace std;

double v1,v2,v,t1,t2,w1,w2,l;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&v1,&v2,&v,&t1,&t2,&w1,&w2,&l);
        int len1 =
        double ans = (w2+t2)*(w1+t1)*l*v;
        double ans2 = ((w2+t2)*v1 + (w1+t1)*v2)*t2;
        double ptans = ans1/ans2;
        printf("%.9f\n",ptans);
    }
    return 0;
}

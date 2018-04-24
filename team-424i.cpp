#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
 
bool flag1=false;
bool flag2=false;
bool flag3=false;
bool flag4=false;
int yy,xx,r;
int main() {
    flag1=false;
    flag2=false;
    bool flag3=false;
    bool flag4=false;
    point emt[4];
    for(int i=0;i<3;i++)
        // scanf("%d%d",&emt[i].x,&emt[i].y);
        cin >>emt[i].x >> emt[i].y;

    for(int i=0;i<3;i++)
        // scanf("%d%d",&emt[i].x,&emt[i].y);
        printf("%d %d\n", emt[i].x ,emt[i].y); 
    // scanf("%d%d%d",&yy,&xx,&r);
    cin >> xx >> yy >> r;
    double d1;
    double d2;
    double tana;
    double x01,y01;
    printf("cnt1:%.16f\n", abs((yy*(emt[1].x-emt[0].x))-(xx*(emt[1].y-emt[0].y)))*1.0);
    printf("cnt1:%.16f  %.16f\n", (yy*(emt[2].x-emt[0].x))*1.0,(xx*(emt[2].y-emt[0].y))*1.0);
    d1 = abs((yy*(emt[1].x-emt[0].x))-(xx*(emt[1].y-emt[0].y)))*1.0/(sqrt(xx*xx+yy*yy));
    d2 = abs((yy*(emt[2].x-emt[0].x))-(xx*(emt[2].y-emt[0].y)))*1.0/(sqrt(xx*xx+yy*yy));
    printf("d1:%.16f\n", d1);
    printf("d2:%.16f\n", d2);

    if(d1 < 2*r && d2 < 2*r)
    {
        double dis1 = (emt[0].x-emt[1].x)*(emt[0].x-emt[1].x)*1.0 + (emt[0].y-emt[1].y)*(emt[0].y-emt[1].y)*1.0;
        double dis2 = (emt[0].x-emt[1].x)*(emt[0].x-emt[1].x)*1.0 + (emt[0].y-emt[1].y)*(emt[0].y-emt[1].y)*1.0;
        if(dis1<dis2)
        {
            flag1 = true;
            y01 = sqrt(4*r*r-d1);
            x01 = d1;
            double tanab,tanb;
            tanab = yy*1.0/xx;
            tanb = x01*1.0/y01;
            tana = (tanab-tanb)/(1+tanab*tanb);
            d2 = (tana*emt[2].x-emt[2].y-tana*emt[1].x+emt[1].y)/(tana*tana + 1);
            if(d2 < 2*r) flag4 = true;
        }else if(dis1>dis2){
            flag2 = true;
            y01 = sqrt(4*r*r-d2);
            x01 = d2;
            double tanab,tanb;
            tanab = yy*1.0/xx;
            tanb = x01*1.0/y01;
            tana = (tanab-tanb)/(1+tanab*tanb);
            d1 = (tana*emt[1].x-emt[1].y-tana*emt[2].x+emt[2].y)/(tana*tana + 1);
            if(d1 < 2*r) flag3 = true;
        }
    }
    else if(d1 < 2*r)
    {
        flag1 = true;
        y01 = sqrt(4*r*r-d1);
        x01 = d1;
        double tanab,tanb;
        tanab = yy*1.0/xx;
        tanb = x01*1.0/y01;
        tana = (tanab-tanb)/(1+tanab*tanb);
        d2 = (tana*emt[2].x-emt[2].y-tana*emt[1].x+emt[1].y)/(tana*tana + 1);
        if(d2 < 2*r) flag4 = true;
    }
    else if(d2 < 2*r)
    {
        flag2 = true;
        y01 = sqrt(4*r*r-d2);
        x01 = d2;
        double tanab,tanb;
        tanab = yy*1.0/xx;
        tanb = x01*1.0/y01;
        tana = (tanab-tanb)/(1+tanab*tanb);
        d1 = (tana*emt[1].x-emt[1].y-tana*emt[2].x+emt[2].y)/(tana*tana + 1);
        printf("dxxx1:%.16f\n", d1);

        if(d1 < 2*r) flag3 = true;
    }
 
    if(flag1&&flag4) printf("1\n");
    else if(flag2&&flag3) printf("2\n");
    else if(flag1&&!flag4) printf("3\n");
    else if(flag2&&!flag3) printf("4\n");
    else if(!flag1&&!flag2) printf("5\n");
    return 0;
}
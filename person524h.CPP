#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x,y;
    int a;
}emt[107];
int w,h,n;
int main()
{
    while(~scanf("%d%d%d",&w,&h,&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&emt[i].x,&emt[i].y,&emt[i].a);
        int sum=w*h;
//        int wnow=w,hnow=h;
        int wl=0,hd=0;
        int wr=w,ht=h;
        for(int i=1;i<=n;i++)
        {
            if(emt[i].a==1)
            {
                wl = max(wl,emt[i].x);
            }
            else if(emt[i].a==2)
            {
                wr = min(wr,emt[i].x);
            }
            else if(emt[i].a==3)
            {
                hd = max(hd,emt[i].y);
            }
            else if(emt[i].a==4)
            {
                ht = min(ht,emt[i].y);
            }
            if(wl >= wr || hd >= ht) break;
        }
        (wl > wr || hd > ht) == true? printf("0\n"):printf("%d\n",(wr-wl)*(ht-hd));
    }
    return 0;
}

// #include<cstdio>
// #include<cstring>
// #include<algorithm>
// using namespace std;
// struct point
// {
//     int x,y;
// }point[500];
// struct node
// {
//     int zx,zy;
// }a[250000];

// bool cmp(node p,node q)
// {
//     if(p.zx==q.zx)
//     {
//         return p.zy<q.zy;
//     }
//     else return p.zx<q.zx;
// }

// int main()
// {
//     int n;
//     while(~scanf("%d",&n))
//     {
//         for(int i=0;i<n;i++)
//         {
//             scanf("%d%d",&point[i].x,&point[i].y);
//         }
//         int cnt=0;
//         for(int i=0;i<n-1;i++)
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                 a[cnt].zx=point[i].x+point[j].x;
//                 a[cnt].zy=point[i].y+point[j].y;
//                 cnt++;
//             }
//         }
//         sort(a,a+cnt,cmp);
//         int sum=0;
//         int num=1;
//         for(int i=1;i<cnt;i++)
//         {
//             if(a[i].zx==a[i-1].zx&&a[i].zy==a[i-1].zy)
//             {
//                 num++;
//             }
//             else
//             {
//                 sum+=(num*(num-1)/2);
//                 num=1;
//             }
//         }
//         printf("%d\n",sum);
//     }
//     return 0;
// }

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct point
{
    int x,y;
}emt[507];
struct cntpoint
{
    int x,y;
}cemt[250007];

bool cmp(cntpoint a, cntpoint b)
{
    if(a.x==b.x)
        return a.y < b.y;
    else return a.x < b.x;
}

int main(int argc, char const *argv[])
{
    int n;
    while(~scanf("%d",&n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d",&emt[i].x,&emt[i].y);
        }
        int cnt=0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n && i!=j; ++j)
            {
                cemt[cnt].x = emt[i].x+emt[j].x;
                cemt[cnt++].y = emt[i].y+emt[j].y;
            }
        }
        sort(cemt,cemt+cnt,cmp);
        int sum=0;
        int cont=1;
        for (int i = 1; i < cnt; ++i)
        {
            if(cemt[i].x==cemt[i-1].x && cemt[i].y==cemt[i-1].y)
                cont++;
            else 
            {
                sum += (cont*(cont-1)/2);
                cont=1;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
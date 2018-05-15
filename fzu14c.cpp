#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct point
{
    int x,y;
}point[500];
struct node
{
    int zx,zy;
}a[250000];

bool cmp(node p,node q)
{
    if(p.zx==q.zx)
    {
        return p.zy<q.zy;
    }
    else return p.zx<q.zx;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);
        }
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                a[cnt].zx=point[i].x+point[j].x;
                a[cnt].zy=point[i].y+point[j].y;
                cnt++;
            }
        }
        sort(a,a+cnt,cmp);
        int sum=0;
        int num=1;
        for(int i=1;i<cnt;i++)
        {
            if(a[i].zx==a[i-1].zx&&a[i].zy==a[i-1].zy)
            {
                num++;
            }
            else
            {
                sum+=(num*(num-1)/2);
                num=1;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
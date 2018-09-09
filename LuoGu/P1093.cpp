#include<bits/stdc++.h>
using namespace std;

//-------------
struct node
{
    int id,a,b,c,sum;
}emt[307];
int n;

bool cmp(node a,node b)
{
    if(a.sum!=b.sum)return a.sum>b.sum;
    else if(a.a!=b.a) return a.a>b.a;
    else return a.id<b.id;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d %d %d",&emt[i].a,&emt[i].b,&emt[i].c);
        emt[i].id = i;
        emt[i].sum = emt[i].a+emt[i].b+emt[i].c;
    }
    sort(emt+1,emt+1+n,cmp);
    for(int i=1;i<=min(5,n);i++)
    {
        printf("%d %d\n",emt[i].id,emt[i].sum);
    }
    return 0;
}

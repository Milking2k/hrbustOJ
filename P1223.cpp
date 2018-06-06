#include<bits/stdc++.h>
using namespace std;
//-----------------------------
struct node
{
    int no,val;
}emt[2000007];
int n,m;

bool cmp(node a,node b){return a.val<b.val;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&emt[i].val),emt[i].no=i;

    double ans=0;
    int i,sum=0;
    sort(emt+1,emt+1+n,cmp);

    for(i=1;i<=n;i++)
    {
        i==n?printf("%d\n",emt[i].no):printf("%d ",emt[i].no);
        sum += emt[i].val;
        ans += sum;
    }
    printf("%.2f\n",(ans-sum)/n);
    return 0;
}

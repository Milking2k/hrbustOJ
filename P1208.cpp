#include<bits/stdc++.h>
using namespace std;
//-----------------------------
struct node
{
    int num,val;
}emt[2000007];
int n,m;

bool cmp(node a,node b){return a.val<b.val;}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d %d",&emt[i].val,&emt[i].num);

    int ans=0,num=0,i;
    sort(emt+1,emt+1+m,cmp);
    for(i=1;i<=m;i++)
    {
        ans+=emt[i].val*emt[i].num;
        num+=emt[i].num;
        if(num>=n) break;
    }
    ans = ans - max(num-n,0)*emt[i].val;
    printf("%d\n",ans);
    return 0;
}



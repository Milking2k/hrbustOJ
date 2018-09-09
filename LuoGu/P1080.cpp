#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e17+7;
//-----------------------------
int n;
struct node
{
    int l,r;
    long long per;
}emt[1000007];

bool cmp(node a,node b)
{
    if(a.per == b.per)return a.l<b.l;
    return a.per<b.per;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        scanf("%d %d",&emt[i].l,&emt[i].r);
        emt[i].per = 1ll*emt[i].l*emt[i].r;
    }

    sort(emt+1,emt+1+n,cmp);
    double ans=0;
    long long cnt=1;

    for(int i=1;i<=n;i++)
    {
        ans = max(ans,cnt*1.0/emt[i].r);
        cnt = cnt * 1ll*emt[i].l%MOD;
    }

    printf("%.0f\n",ans);
    return 0;
}



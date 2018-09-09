#include<bits/stdc++.h>
using namespace std;

//-----------------------------
int n;
struct node
{
    int st,ed;
}emt[1000007];

bool cmp(node a,node b){return a.ed<b.ed;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d %d",&emt[i].st,&emt[i].ed);

    sort(emt+1,emt+1+n,cmp);
    int ed=emt[1].ed,ans=1;

    for(int i=1;i<=n;i++) if(emt[i].st>=ed) ans++,ed=emt[i].ed;

    printf("%d\n",ans);
    return 0;
}


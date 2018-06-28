#include<bits/stdc++.h>
using namespace std;

struct node
{
    int pos,val;
}emt[207];
int n;
int vis[207];
vector<node> s;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%d",&emt[i].val);
        emt[i].pos = i;
    }

    int ans=0;
    for(int i=1;i<=2*n;i++)
    {
        if(!vis[emt[i].val])
        {

        }
    }
    printf("%d\n",ans);
    return 0;
}

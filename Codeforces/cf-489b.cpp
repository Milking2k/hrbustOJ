#include<bits/stdc++.h>
using namespace std;

const int MAX_NUM = 100007;

int t,n,m;
int emt[MAX_NUM];
int vis[2*MAX_NUM];
int main()
{
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));

    int sum = 0;
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if(vis[x + MAX_NUM]==0 && x != 0)
        {
            sum++;
            vis[x + MAX_NUM] = 1;
        }
    }
    printf("%d\n",sum);
    return 0;
}

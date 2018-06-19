#include<bits/stdc++.h>
using namespace std;

int n,m,t;
int emt[1000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        long long sum=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&emt[i]);
        sort(emt+1,emt+1+n);
        for(int i=n;i>= n-m+1;i--)
        {
            sum+=emt[i];
        }
        printf("%d\n",sum);

    }
    return 0;
}

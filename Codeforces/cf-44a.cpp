#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int emt[107];
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++)
    {
        scanf("%d",&emt[i]);
    }
    sort(emt+1,emt+1+n/2);
    int t1=0,t2=0;
    for(int i=1;i<=n/2;i++)
    {
        t1 += abs(emt[i]-(2*i-1));
        t2 += abs(emt[i]-2*i);
    }
    printf("%d",min(t1,t2));
    return 0;
}
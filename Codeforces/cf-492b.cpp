#include<bits/stdc++.h>
using namespace std;

int n;
int emt[100007];
int main()
{
    scanf("%d",&n);

    int minnum = 0x3f3f3f3f;
    int minpos = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &emt[i]);
        if(emt[i] < minnum) minnum = emt[i];
    }

    int ans = minnum%n;

    for(int i = 1;i<=2*n;i++)
    {
        if(emt[ans] - minnum <= 0) break;
        ans = (ans+1)%n;
        minnum++;
    }
    printf("%d\n",ans+1);
    return 0;
}

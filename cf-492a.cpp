#include<bits/stdc++.h>
using namespace std;


int t,n,m;
int emt[5] = {100,20,10,5,1};
int main()
{
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<=5;i++)
    {
        if(n/emt[i] != 0 && n!=0)
        {
            ans += n/emt[i];
            n %= emt[i];
        }
    }
    printf("%d\n",ans);

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

//-----------------------------
int n,w;
int emt[30007];

int main()
{
    scanf("%d %d",&w,&n);
    for(int i=1;i<=n;i++) scanf("%d",&emt[i]);

    int i=1,j=n,ans=0;
    sort(emt+1,emt+1+n);

    while(i<=j)
    {
        if(emt[j]+emt[i]<=w)
            ans++,i++,j--;
        else ans++,j--;
    }
    printf("%d\n",ans);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
//-----------------------------
int n,m;
int emt[100007];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&emt[i]);

    int cnt=m;
    int ans=0;
    for(int i=1;i<=n;)
    {
        while(cnt-emt[i]>=0 && i<=n)cnt = cnt - emt[i++];// Íùºó¼Ó1
        ans++;
        cnt=m;
//        printf("%d\n",i);
    }
    printf("%d\n",ans);
    return 0;
}


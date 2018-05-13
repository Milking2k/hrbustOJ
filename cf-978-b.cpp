#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char emt[107];
int n;
int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
//            scanf("%c",&emt[i]);
            cin>>emt[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(emt[i]=='x'&&emt[i+1]=='x'&&emt[i+2]=='x') ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
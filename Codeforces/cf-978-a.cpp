#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
int a[57];
int b[57];
int vis[1007];

int len;
int main()
{
    while(~scanf("%d",&n))
    {
        memset(vis,0,sizeof(vis));
        int x;
        len=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&b[i]);

        }
        for(int i=n-1;i>=0;i--)
            if(!vis[b[i]])a[len++] = b[i],vis[b[i]]=1;

        printf("%d\n",len);
        for(int i=len-1;i>=0;i--)
        {
            printf("%d",a[i]);
            if(i!=0)printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 50007;
int n;
int c[MAXN];
int lowbit(int x)
{
    return x&(-x);
}
void add(int i,int val)
{
    while(i<=n)
    {
        c[i]+=val;
        i+=lowbit(i);
    }
}
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
    int t;
    scanf("%d",&t);
    int ptCase=0;
    while(t--)
    {
        ptCase++;
        scanf("%d",&n);
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            add(i,x);
        }
        printf("Case %d:\n",ptCase);
        char str[17];
        int a,b;
        while(scanf("%s",str) && strcmp(str,"End")!=0)
        {
            scanf("%d%d",&a,&b);
            if(strcmp(str,"Add")==0)
            {
                add(a,b);
            }
            else if(strcmp(str,"Sub")==0)
            {
                add(a,-b);
            }
            else
            {
                printf("%d\n",sum(b)-sum(a-1));
            }
        }
    }


    return 0;
}

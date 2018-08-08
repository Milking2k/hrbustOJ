#include<bits/stdc++.h>
#define read(x) scanf("%d",&x)
using namespace std;
const int maxn=1e5;
int a[maxn];
 
int main()
{
    int T;
    read(T);
    int Cas=1;
    while(T--)
    {
        int n;
        read(n);
        int pos=0;
        int sum=0;
        memset(a,0,sizeof(a));
        for(int i=1; i<=n/2; i++)
        {
            if(n%i==0)
            {
                a[pos++]=i;
                sum+=i;
            }
        }
        if(sum==n)
        {
            printf("Case %d: %d = 1",Cas++,n);
            for(int i=1; i<pos; i++)
            {
                printf(" + %d",a[i]);
            }
            puts("");
        }
        else
        {
            printf("Case %d: Not perfect.\n",Cas++);
        }
    }
}
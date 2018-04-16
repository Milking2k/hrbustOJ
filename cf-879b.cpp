#include <bits/stdc++.h>
using namespace std;

long long int n;
long long int k;
int a[505];
int b[505];
int maxnum;
int pos;
int main()
{
    while(~scanf("%lld%lld",&n,&k))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        maxnum = 0;
        pos=0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d",&a[i]);
            if(a[pos] < a[i])
            {
                // printf("maxnum:%d\n", maxnum);
                if(pos!=0)
                    maxnum++;
                b[pos] = maxnum;
                pos=i;
                maxnum=0;
            }
            else if(a[pos]>a[i])
            {
                maxnum++;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if(b[i] >= k)
            {
                printf("%d\n", a[i]);
                break;
            }
            else if(i==n-1)
            {
                printf("%d\n", a[pos]);
            }
        }
    }
    
    return 0;
}
/*
5 2
2 1 3 4 5
5 2
1 4 3 5 2
*/
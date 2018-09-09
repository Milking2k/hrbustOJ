#include<bits/stdc++.h>
using namespace std;
int n,k;

int quickmod(int x,int n)
{
    int res=1;
    while(n>0)
    {
        if(n&1)res = (res*x);
        x=x*x;
        n>>=1;
    }
    return res;
}

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        printf("%d\n",k*quickmod(k-1,n-1));
    }
    return 0;
}


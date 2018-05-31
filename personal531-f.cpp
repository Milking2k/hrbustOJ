//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;

// --------------
int n;
int a,b,c;
int main()
{
    while(~scanf("%d",&n))
    {
        int ans=0;
        while(n--)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a<60 || b<60 || c<60) continue;
            else if(a+b+c >= 240) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}

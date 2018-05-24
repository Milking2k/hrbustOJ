#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
    while(~scanf("%d%d%d",&a,&b,&c))
    {
        if(a+b==c || a+c==b || b+c == a)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}


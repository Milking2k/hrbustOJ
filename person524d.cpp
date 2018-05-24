#include<bits/stdc++.h>
using namespace std;



int a,b,c;
int main()
{
    while(~scanf("%d%d%d",&a,&b,&c))
{


    if(a==b && b==c)
    {
        printf("1");
    }
    else if(a==b && b!=c || (a==c&&b!=c) || (b==c && a!=c))printf("2");
    else printf("3");
    }
    return 0;
}
